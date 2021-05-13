import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like


norm_df = pd.read_csv('part_random_norm_obs.csv')
uni_df = pd.read_csv('part_random_uni_obs.csv')


n_norm = norm_df['num_elements'].to_numpy()
comp_norm = norm_df['avg_comparison'].to_numpy()
time_norm = norm_df['avg_time'].to_numpy()

n_uni = uni_df['num_elements'].to_numpy()
comp_uni = uni_df['avg_comparison'].to_numpy()
time_uni = uni_df['avg_time'].to_numpy()

x_axis = range(1,18)

fig, axis = plt.subplots(2, 1, figsize=(10, 7))

fig.suptitle('Comparision and Time Ratio for Normal Distribution')

axis[0].plot(x_axis,comp_norm, 'o-', label='Normal')
axis[0].plot(x_axis,comp_uni, 'o-', label='Uniform')
axis[0].legend()
axis[0].set_ylabel('comparision')

axis[1].plot(x_axis,time_norm, 'o-', label='Normal')
axis[1].plot(x_axis,time_uni, 'o-', label='Uniform')

axis[1].legend()
axis[1].set_ylabel('time taken (ms)')

plt.xlabel(r'n [array size = $2^n$]')

plt.savefig('observation.png')
