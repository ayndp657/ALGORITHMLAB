import numpy as np  # for arrays
import matplotlib.pyplot as plt  # for plotting
import pandas as pd

df = pd.read_csv('normalized_normal_distribution.csv')

plt.figure(figsize=(10,6))
plt.xlabel("Number")
plt.ylabel("No. of Occurrence")
plt.hist(df['value'].to_numpy(),bins=100)
plt.title("Histogram of Normal Dataset")
plt.savefig('Histogram of Normal Dataset')