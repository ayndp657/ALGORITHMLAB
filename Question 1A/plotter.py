import numpy as np
import csv
import matplotlib.pyplot as plt

random_numbers = np.zeros(201)

with open('./Question 1A/uniform_distribution.csv') as csv_file:
    csv_reader = csv.reader(csv_file)
    line_count = 0
    for row in csv_reader:
        random_numbers[line_count] = row[0]
        line_count = line_count + 1
    print(f"Processed {line_count} lines.")

plt.figure("Histogram of Uniform Distribution Dataset")
plt.title("Histogram of Uniform Distribution Dataset")
plt.xlabel("Number")
plt.ylabel("No. of Occurrence")
plt.hist(random_numbers, bins=range(100))
plt.show()