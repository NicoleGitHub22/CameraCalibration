import numpy as np
import cv2 as cv
import glob
import os

# Directory for saving the images with drawn corners
img_dir = '../Lightstage/Build/Server/Undistorted/'
if not os.path.exists(img_dir):
    os.makedirs(img_dir)
    print(f"Created directory {img_dir}")
else:
    print(f"Directory {img_dir} already exists")

# Load the images
images = glob.glob('*.ppm')

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
    
    # crop and save the image
    x, y, w, h = roi
    dst = dst[y:y+h, x:x+w]
    cv.imwrite(f'{img_dir}{image}', dst)

