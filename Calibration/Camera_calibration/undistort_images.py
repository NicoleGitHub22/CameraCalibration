import numpy as np
import cv2 as cv
import glob
import os
import shutil

# Directory for saving the images with drawn corners
img_dir = 'home/bretznic/Documents/GitHub/CameraCalibration/Lightstage/Build/Server/Undistorted/'
if not os.path.exists(img_dir):
    os.makedirs(img_dir)
    print(f"Created directory {img_dir}")
else:
    # Clear existing files in the directory
    for file in os.listdir(img_dir):
        file_path = os.path.join(img_dir, file)
        try:
            if os.path.isfile(file_path) or os.path.islink(file_path):
                os.unlink(file_path)
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path)
        except Exception as e:
            print(f'Failed to delete {file_path}. Reason: {e}')

# Load the distortion and camera matrix from the saved file
calibration_data = np.load('calibration_data.npz')
mtx = calibration_data['mtx']
dist = calibration_data['dist']

# Load the images
images = glob.glob('home/bretznic/Documents/GitHub/CameraCalibration/Lightstage/Build/Server/*.ppm')
print(images)

for image in images:
    # Load the image
    img = cv.imread(image)

    # Check if the image was loaded
    if img is None:
        print(f"Error loading image {image}")
        continue
    h, w = img.shape[:2]
    newcameramtx, roi = cv.getOptimalNewCameraMatrix(mtx, dist, (w,h), 1, (w,h))
    

    # undistort
    dst = cv.undistort(img, mtx, dist, None, newcameramtx)
    print(dst)
    # crop and save the image
    x, y, w, h = roi
    dst = dst[y:y+h, x:x+w]
    filename = os.path.basename(image)  
    save_path = os.path.join(img_dir, filename)
    success = cv.imwrite(save_path, dst)
    if not success:
        print(f"Failed to save image {save_path}")
    else:
        print(f"Image {filename} undistorted and saved to {save_path}")

