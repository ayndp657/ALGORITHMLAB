import numpy as np  # for arrays
import matplotlib.pyplot as plt  # for plotting
import pandas as pd

df = pd.read_csv('normalized_uniform_distribution.csv')


plt.figure("Histogram of Dataset")
plt.xlabel("Number")
plt.ylabel("No. of Occurrence")
plt.hist(df['value'].to_numpy())
plt.show()