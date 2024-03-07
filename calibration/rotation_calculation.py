import numpy as np
import os

def quaternion_to_rotation_matrix(quaternion):
    # Convert a quaternion into a rotation matrix.
    q_w, q_x, q_y, q_z = quaternion
    return np.array([
        [1 - 2*q_y**2 - 2*q_z**2, 2*q_x*q_y - 2*q_z*q_w, 2*q_x*q_z + 2*q_y*q_w],
        [2*q_x*q_y + 2*q_z*q_w, 1 - 2*q_x**2 - 2*q_z**2, 2*q_y*q_z - 2*q_x*q_w],
        [2*q_x*q_z - 2*q_y*q_w, 2*q_y*q_z + 2*q_x*q_w, 1 - 2*q_x**2 - 2*q_y**2]
    ])

def read_average_quaternion(file_path):
    # Read the average quaternion from a file.
    if not os.path.exists(file_path):
        print(f"{file_path} does not exist.")
        return None

    with open(file_path, 'r') as file:
        line = file.readline().strip().split(':')[-1].strip()
        # Attempt to split the line into four parts and convert to float
        parts = line.strip('[]').split()
        if len(parts) != 4:
            print(f"Invalid format in {file_path}. Expected 4 components, got {len(parts)}.")
            return None
        try:
            quaternion = np.array([float(part) for part in parts])
        except ValueError:
            print(f"Could not convert string to float in {file_path}. Check the file format.")
            return None
    return quaternion

def save_rotation_matrix(file_path, rotation_matrix):
    # Save the rotation matrix to a file.
    with open(file_path, 'w') as file:
        for row in rotation_matrix:
            file.write(' '.join(map(str, row)) + '\n')

# Paths for the average quaternion files and the rotation result files
average_quaternion_files = [f'./Average_Quaternions/average_quaternion{i}.txt' for i in range(1, 7)]
rotation_result_files = [f'./Rotation_Results/rotation_result{i}.txt' for i in range(1, 7)]

# Ensure output directories exist
os.makedirs('./Average_Quaternions', exist_ok=True)
os.makedirs('./Rotation_Results', exist_ok=True)

# Calculate and save the rotation matrix for each average quaternion
for avg_file, rot_file in zip(average_quaternion_files, rotation_result_files):
    avg_quaternion = read_average_quaternion(avg_file)
    if avg_quaternion is not None:
        rotation_matrix = quaternion_to_rotation_matrix(avg_quaternion)
        save_rotation_matrix(rot_file, rotation_matrix)
        print(f"Saved rotation matrix to {rot_file}.")
    else:
        print(f"Skipping.")

