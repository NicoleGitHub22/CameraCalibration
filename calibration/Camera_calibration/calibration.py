# ===========================================
# Open CV - Camera Calibration
# ===========================================

import numpy as np
import cv2 as cv
import glob
import os

# inner Corners count x
innerCornerCountX = 6
innerCornerCountY = 4
 
# termination criteria
criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 30, 0.001)
 
# prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
objp = np.zeros((innerCornerCountX*innerCornerCountY,3), np.float32)
objp[:,:2] = np.mgrid[0:innerCornerCountX,0:innerCornerCountY].T.reshape(-1,2)
 
# Arrays to store object points and image points from all the images.
objpoints = [] # 3d point in real world space
imgpoints = [] # 2d points in image plane.

# Directory for saving the images with drawn corners
results_dir = 'results/'
if not os.path.exists(results_dir):
    os.makedirs(results_dir)
 
# Load images
images = glob.glob('*.jpg')

# Process each image
for fname in images:
    img = cv.imread(fname)
    if img is None:
        print(f"Failed to load {fname}")
        continue
    
    # Convert to gray scale
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
 
    # Find the chess board corners
    ret, corners = cv.findChessboardCorners(gray, (innerCornerCountX,innerCornerCountY), None)
    
    # If corners are found, append the object points and image points
    if ret:
        objpoints.append(objp)
        
        # Refine the corner positions
        corners2 = cv.cornerSubPix(gray, corners, (11,11), (-1,-1), criteria)

        # Append the image points
        imgpoints.append(corners2)
        
        # Draw the corners on the image
        cv.drawChessboardCorners(img, (innerCornerCountX,innerCornerCountY), corners2, ret)
        
        # Save the image with drawn corners to the results directory
        results_path = os.path.join(results_dir, os.path.basename(fname))
        cv.imwrite(results_path, img)
    else:
        print(f"No corners found in {fname}.")

# Calibrate the camera
if len(objpoints) > 0 and len(imgpoints) > 0:

    
    ret, mtx, dist, rvecs, tvecs = cv.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)
    
    # Check if calibration was successful
    if ret:  
        print("Calibration was successful.")
        print(f"Calibration matrix: \n{mtx}")
        print(f"Distortion coefficients: {dist}")

        # Convert rotation vectors to rotation matrices using Rodrigues
        rotation_matrices = []
        for rvec in rvecs:
            rotation_matrix, _ = cv.Rodrigues(rvec)
            rotation_matrices.append(rotation_matrix)
        print(f"Rotation matrices: {rotation_matrices}")
        print(f"Translation vectors: {tvecs}")
else:
    print("No valid image points found for calibration.")

# Divide rotation_matrices into chunks of 3
chunks = [rotation_matrices[x:x+3] for x in range(0, len(rotation_matrices), 3)]

for i, chunk in enumerate(chunks, start=1):
    # Construct the filename based on the chunk index
    filename = f"../Matrices_Monitors/matrices_monitor{i}.txt"
    with open(filename, 'w') as file:
        for matrix in chunk:
            # Write each rotation matrix to the file
            # np.savetxt writes an array to a text file.
            np.savetxt(file, matrix, fmt="%s")
            file.write("\n")  # Add a newline to separate matrices
    print(f"Saved rotation matrices to {filename}")

cv.destroyAllWindows()
