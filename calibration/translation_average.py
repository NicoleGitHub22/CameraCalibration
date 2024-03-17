import os
import numpy as np

def calculate_average_vector(file_path):
    vectors = []
    max_length = 0
    with open(file_path, 'r') as file:
        lines = file.readlines()
        if not lines:
            raise ValueError(f"File {file_path} is empty. Skipped")
        
        for line in lines:
            try:
                vector = np.array([float(num) for num in line.split()], dtype=float)
                if vector.size == 0:
                    raise ValueError("Line does not contain a valid vector.")
                vectors.append(vector)
                max_length = max(max_length, len(vector))
            except ValueError as e:
                raise ValueError(f"Invalid data in file {file_path}: {e}")
    
    if not vectors:
        raise ValueError(f"No valid vectors found in file {file_path}.")
    
    # Initialize a list to store the sum of each dimension and a count of how many vectors contribute to each dimension
    dimension_sums = np.zeros(max_length)
    dimension_counts = np.zeros(max_length)
    
    # Sum up each dimension and count the contributions
    for vector in vectors:
        for i, value in enumerate(vector):
            dimension_sums[i] += value
            dimension_counts[i] += 1
    
    # Calculate the average for each dimension
    averages = dimension_sums / dimension_counts
    
    return averages

def process_files():
    # Define source and target directories
    source_dir = 'Average_Translations'
    target_dir = 'Translation_Results'
    os.makedirs(target_dir, exist_ok=True)

    # Process each file in the source directory
    for i, filename in enumerate(os.listdir(source_dir), start=1):
        file_path = os.path.join(source_dir, filename)
        try:
            average_vector = calculate_average_vector(file_path)
            # Define the path for the result file
            result_file_path = os.path.join(target_dir, f'translation_result{i}.txt')
            with open(result_file_path, 'w') as result_file:
                result_file.write(' '.join(map(str, average_vector)))
        except ValueError as e:
            print(e)
            continue  # Skip files with errors

try:
    process_files()
    print("All files processed.")
except Exception as e:
    print(f"An unexpected error occurred: {e}")
