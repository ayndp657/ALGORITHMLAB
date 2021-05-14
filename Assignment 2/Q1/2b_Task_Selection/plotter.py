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


brute_t_ratio = time_brute / 2**n_brute
plt.figure()
plt.plot(n_brute, brute_t_ratio, '.-')
plt.xlabel('Array Size(n)')
plt.ylabel('Time taken / 2^n')
plt.title('Brute Force Algorithm')
plt.xticks(range(2, 26, 2))
plt.savefig('brute.png',transparent=True)

greedy_t_ratio = time_greedy / (n_greedy* np.log2(n_greedy))
plt.figure()
plt.plot(n_greedy[::2], greedy_t_ratio[::2], '.-')
plt.xlabel('Array Size(n)')
plt.ylabel('Time taken / (n*lgn)')
plt.title('Greedy Algorithm')
plt.xticks(range(2, 50, 5))
plt.savefig('greedy.png',transparent=True)

plt.figure()
plt.plot(n_greedy[:24], time_greedy[:24], '.-', label='Greedy')
plt.plot(n_brute, time_brute, '.-', label='Brute Force')
plt.xlabel('Array Size')
plt.ylabel('Time taken in ms')
plt.title('Task Selection: Greedy vs Brute Force')
plt.legend()
plt.xticks(range(2, 26, 2))
plt.savefig('greedy_vs_brute.png',transparent=True)

