import os
import numpy as np

def quaternion_calculation(R):
    q_w = 0.5 * np.sqrt(1 + R[0, 0] + R[1, 1] + R[2, 2])
    if q_w < 1e-8:
        if R[0, 0] > R[1, 1] and R[0, 0] > R[2, 2]:
            q_x = np.sqrt(1 + R[0, 0] - R[1, 1] - R[2, 2]) / 2
            q_y = (R[1, 0] + R[0, 1]) / (4 * q_x)
            q_z = (R[0, 2] + R[2, 0]) / (4 * q_x)
            q_w = (R[2, 1] - R[1, 2]) / (4 * q_x)
        elif R[1, 1] > R[2, 2]:
            q_y = np.sqrt(1 - R[0, 0] + R[1, 1] - R[2, 2]) / 2
            q_x = (R[1, 0] + R[0, 1]) / (4 * q_y)
            q_z = (R[2, 1] + R[1, 2]) / (4 * q_y)
            q_w = (R[0, 2] - R[2, 0]) / (4 * q_y)
        else:
            q_z = np.sqrt(1 - R[0, 0] - R[1, 1] + R[2, 2]) / 2
            q_x = (R[0, 2] + R[2, 0]) / (4 * q_z)
            q_y = (R[2, 1] + R[1, 2]) / (4 * q_z)
            q_w = (R[1, 0] - R[0, 1]) / (4 * q_z)
    else:
        q_x = (R[2, 1] - R[1, 2]) / (4 * q_w)
        q_y = (R[0, 2] - R[2, 0]) / (4 * q_w)
        q_z = (R[1, 0] - R[0, 1]) / (4 * q_w)

    return np.array([q_w, q_x, q_y, q_z])

def process_matrices_from_file(file_path, output_file_path):
    # Check if the input file exists
    if not os.path.exists(file_path):
        print(f"{file_path} does not exist. Creating a placeholder file.")
        with open(file_path, 'w') as file:
            file.write("Replace this text with your matrices, formatted as instructed.\n")
        # Since the file is just created and contains no valid matrices, skip further processing
        return
    
    try:
        with open(file_path, 'r') as file:
            content = file.read().strip()
        
        if not content:
            raise ValueError(f"The file {file_path} is empty.")
        
        matrices_str = content.split('\n\n')
        if not matrices_str:
            raise ValueError(f"No valid matrices found in {file_path}.")

        with open(output_file_path, 'w') as output_file:
            for matrix_str in matrices_str:
                matrix_rows = matrix_str.split('\n')
                if not all(matrix_rows):
                    raise ValueError(f"Invalid matrix format detected in {file_path}.")
                R = np.array([row.split('\t') for row in matrix_rows], dtype=float)
                
                quaternion = quaternion_calculation(R)
                output_file.write(f"{quaternion}\n")
                
    except ValueError as ve:
        print(ve)
    except Exception as e:
        print(f"An error occurred while processing {file_path}: {e}")

# List of input and output file pairs
file_pairs = [
    ('./matrices_monitor1.txt', './quaternion_results_monitor1.txt'),
    ('./matrices_monitor2.txt', './quaternion_results_monitor2.txt'),
    ('./matrices_monitor3.txt', './quaternion_results_monitor3.txt'),
    ('./matrices_monitor4.txt', './quaternion_results_monitor4.txt'),
    ('./matrices_monitor5.txt', './quaternion_results_monitor5.txt'),
    ('./matrices_monitor6.txt', './quaternion_results_monitor6.txt'),
]

for input_file, output_file in file_pairs:
    process_matrices_from_file(input_file, output_file)
    print(f"Processed {input_file} and attempted to save results to {output_file}.")
