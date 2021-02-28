import numpy as np  # for arrays
import csv  # for reading .csv files
import matplotlib.pyplot as plt  # for plotting

# .csv has 200 values, so defining 200 value array
random_numbers = np.zeros(200)

with open('./Question 1A/uniform_distribution.csv') as csv_file:  # while .csv file is open
    csv_reader = csv.reader(csv_file, delimiter=',')  # define .csv file reader
    line_count = 0  # linecount made as index of array
    for row in csv_reader:  # parse through every lines
        # first value of every line is the random number
        random_numbers[line_count] = row[0]
        line_count = line_count + 1
    print(f"Processed {line_count} lines.")

plt.figure("Histogram of Uniform Distribution Dataset")
plt.title("Histogram of Uniform Distribution Dataset")
plt.xlabel("Number")
plt.ylabel("No. of Occurrence")
plt.hist(random_numbers, bins=range(100))
plt.show()