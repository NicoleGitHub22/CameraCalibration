import cv2
import numpy as np
import glob
import os

# Load the calibration data
calibration_data = np.load('calibration_data.npz')
K = calibration_data['mtx']
dist = calibration_data['dist']

# Assuming you have a function to load R and T for each monitor
def load_extrinsics(monitor_id):
    rotation_filename = f"home/bretznic/Documents/GitHub/CameraCalibration/Calibration/Calculations/Matrices_Monitors/matrices_monitor{monitor_id}.txt"
    translation_filename = f"home/bretznic/Documents/GitHub/CameraCalibration/Calibration/Calculations/Translation_Results/translation_result{monitor_id}.txt"
    R = np.loadtxt(rotation_filename)
    T = np.loadtxt(translation_filename)
    return R, T

def extract_lit_up_pixels(displayed_image_path, brightness_threshold=200):

    image = cv2.imread(displayed_image_path, cv2.IMREAD_GRAYSCALE)
    _, lit_up_pixels = cv2.threshold(image, brightness_threshold, 255, cv2.THRESH_BINARY)
    lit_up_coords = np.column_stack(np.where(lit_up_pixels > 0))
    return lit_up_coords


def map_displayed_to_captured(displayed_image_filename):
    
    parts = displayed_image_filename.split('-')
    monitor_id = parts[-2]  
    image_number_parts = parts[1:-2]
    captured_image_filename = f"{'-'.join(image_number_parts)}.ppm"
    captured_image_path = f"home/bretznic/Documents/GitHub/CameraCalibration/Lightstage/Build/Server/{captured_image_filename}"
    return captured_image_path




# Load displayed image information (e.g., key features or "lit up" pixels)
displayed_image_info = load_displayed_image_info('path/to/displayed_image')

# Map displayed image to captured image
captured_image_filename = map_displayed_to_captured(displayed_image_info['filename'])

# Load the corresponding captured image
captured_image = cv2.imread(f'path/to/captured/images/{captured_image_filename}')

# Use the known positions from displayed_image_info to guide ray casting
# This might involve setting light_up_pixels based on displayed_image_info
light_up_pixels = get_light_up_pixels_from_displayed_info(displayed_image_info)

# Proceed with ray casting using light_up_pixels
ray_casting_for_monitor(monitor_id, light_up_pixels, camera_position, monitor_plane)

# Identify features or "lit up" pixels in the displayed image
# This step is highly dependent on your specific application
# For example, you might have already identified these in load_displayed_image_info

# For each feature, convert its pixel coordinates to normalized image coordinates
normalized_coords = [pixel_to_normalized_coordinates(pixel, K, dist) for pixel in displayed_image_info['features']]

# Perform ray casting for each feature
for coords in normalized_coords:
    # You'll need the camera position and the monitor plane equation for this
    camera_position = np.array([0, 0, 0])  # Example position
    monitor_plane = ...  # Define the monitor plane equation
    ray_casting_for_monitor(monitor_id, coords, camera_position, monitor_plane)

# Analyze and visualize the results
