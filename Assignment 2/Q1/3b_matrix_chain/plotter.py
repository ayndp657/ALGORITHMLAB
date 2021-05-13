import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like

dp_df = pd.read_csv('dp_matrixchain.csv')
recursive_df = pd.read_csv('naive_matrixchain.csv')

n_dp = dp_df['n'].to_numpy()
time_dp = dp_df['avg_time_take_ms'].to_numpy()

n_recursize = recursive_df['n'].to_numpy()
time_recursize = recursive_df['avg_time_take_ms'].to_numpy()

plt.figure()
plt.plot(n_dp, time_dp, 'o-', label='DP')
plt.plot(n_recursize, time_recursize, 'o-', label='Recursive')
plt.xlabel('Array Size')
plt.ylabel('Time taken in ms')
plt.title('Matrix Chain Multiplication: DP vs Recursive')
plt.legend()
plt.xticks(range(3,23))
plt.savefig('observation.png')
