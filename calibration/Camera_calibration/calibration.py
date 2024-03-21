# ===========================================
# Open CV - Camera Calibration
# ===========================================

import numpy as np
import cv2 as cv
import glob
 
# termination criteria
criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 30, 0.001)
 
# prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
objp = np.zeros((6*7,3), np.float32)
objp[:,:2] = np.mgrid[0:7,0:6].T.reshape(-1,2)
 
# Arrays to store object points and image points from all the images.
objpoints = [] # 3d point in real world space
imgpoints = [] # 2d points in image plane.
 
images = glob.glob('*.jpg')
 
for fname in images:
    # Resize the image to a specific size, e.g., 800x600
    resized_img = cv.resize(img, (800, 600))
    cv.imshow('Resized Image', resized_img)
    cv.waitKey(500)
    if resized_img is None:
        print(f"Failed to load {fname}")
        continue
    cv.imshow('Loaded Image', resized_img)
    cv.waitKey(500)  # Adjust time as needed

for fname in images:
 img = cv.imread(fname)
 gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
 
 # Find the chess board corners
 ret, corners = cv.findChessboardCorners(gray, (6,4), None)
 
 # If found, add object points, image points (after refining them)
 if ret == True:
    objpoints.append(objp)
    corners2 = cv.cornerSubPix(gray, corners, (11,11), (-1,-1), criteria)
    imgpoints.append(corners2)
 
    # Draw and display the corners
    cv.drawChessboardCorners(img, (6,4), corners2, ret)
    cv.imshow('img', img)
    cv.waitKey(500)
    
print(f"Number of images processed: {len(images)}")
print(f"Number of object points: {len(objpoints)}")
print(f"Number of image points: {len(imgpoints)}")

cv.destroyAllWindows()

if len(objpoints) > 0 and len(imgpoints) > 0:
    ret, mtx, dist, rvecs, tvecs = cv.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)
else:
    print("No valid image points found for calibration.")



