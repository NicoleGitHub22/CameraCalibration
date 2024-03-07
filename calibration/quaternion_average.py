import numpy as np
import os

def read_quaternions_from_file(file_path):
    quaternions = []
    with open(file_path, 'r') as file:
        for line in file:
            # Remove leading and trailing whitespace and brackets
            line = line.strip().strip('[]')
            # Assuming quaternion components are separated by spaces
            parts = line.split()
            # Ensure that we have exactly 4 components for a valid quaternion
            if len(parts) == 4:
                try:
                    quaternion = np.array([float(part) for part in parts])
                    quaternions.append(quaternion)
                except ValueError as e:
                    raise ValueError(f"Could not convert string to float in line: '{line}'. Error: {e}")
            else:
                raise ValueError(f"Invalid quaternion format in line: '{line}'. Expected 4 components.")
    return quaternions

def average_quaternions(quaternions):
    # Simple component-wise average
    sum_q = np.sum(quaternions, axis=0)
    average_q = sum_q / len(quaternions)
    # Normalize the quaternion
    norm_q = np.linalg.norm(average_q)
    return average_q / norm_q

# List of output files containing quaternions
output_files = [
    './quaternion_results_monitor1.txt',
    './quaternion_results_monitor2.txt',
    './quaternion_results_monitor3.txt',
    './quaternion_results_monitor4.txt',
    './quaternion_results_monitor5.txt',
    './quaternion_results_monitor6.txt',
]

# Corresponding files to save the average quaternions
average_output_files = [
    './average_quaternion1.txt',
    './average_quaternion2.txt',
    './average_quaternion3.txt',
    './average_quaternion4.txt',
    './average_quaternion5.txt',
    './average_quaternion6.txt',
]

# Calculate and save the average quaternion for each monitor
for file_path, average_file_path in zip(output_files, average_output_files):
    if os.path.exists(file_path):
        quaternions = read_quaternions_from_file(file_path)
        if quaternions:
            average_q = average_quaternions(quaternions)
            with open(average_file_path, 'w') as file:
                file.write(f"{average_q}\n")
            print(f"Saved average quaternion for {file_path} to {average_file_path}.")
        else:
            print(f"No quaternions found in {file_path}.")
    else:
        print(f"{file_path} does not exist.")
