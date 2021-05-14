import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like

brute_df = pd.read_csv('brute_force.csv')
greedy_df = pd.read_csv('greedy.csv')

n_greedy = greedy_df['n'].to_numpy()
time_greedy = greedy_df['avg_time_taken_ms'].to_numpy()

n_brute = brute_df['n'].to_numpy()
time_brute = brute_df['avg_time_taken_ms'].to_numpy()

plt.figure()
plt.plot(n_greedy, time_greedy, '.-', label='Greedy')
plt.plot(n_brute, time_brute, '.-', label='Brute Force')
plt.xlabel('Array Size')
plt.ylabel('Time taken in ms')
plt.title('Task Selection: Greedy vs Brute Force')
plt.legend()
plt.xticks(range(2, 26, 2))
plt.savefig('greedy_vs_brute.png')
