import numpy as np
import cv2 as cv
import glob
import os

# Directory for saving the images with drawn corners
img_dir = '../../Lightstage/Build/Server/Undistorted/'
if not os.path.exists(img_dir):
    os.makedirs(img_dir)
    print(f"Created directory {img_dir}")

# Load the distortion and camera matrix
dist = np.array([[-0.366189821013305, 0.149372244894956, 0, 0, 0]])
mtx = np.array([[1.54012449012411e+03, 0.00000000e+00, 9.71989736134935e+02],
                [0.00000000e+00, 1.53936261608263e+03, 5.90802005497721e+02],
                [0.00000000e+00, 0.00000000e+00, 1.00000000e+00]])




# Load the images
images = glob.glob('*.jpg')
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
    cv.imwrite(f'{img_dir}{image}', dst)
    print(f"Image {image} undistorted and saved to {img_dir}")

