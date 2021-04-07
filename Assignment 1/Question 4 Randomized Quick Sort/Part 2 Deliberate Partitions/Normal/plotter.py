import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like


part_1_50000_df = pd.read_csv('part_1_50000_obs.csv')
part_1_10000_df = pd.read_csv('part_1_10000_obs.csv')
part_1_5000_df = pd.read_csv('part_1_5000_obs.csv')
part_1_1000_df = pd.read_csv('part_1_1000_obs.csv')
normal_df = pd.read_csv('part_random_obs.csv') 

n_1_50000 = part_1_50000_df['num_elements'].to_numpy()
comp_1_50000 = part_1_50000_df['avg_comparison'].to_numpy()
time_1_50000 = part_1_50000_df['avg_time'].to_numpy()

n_1_10000 = part_1_10000_df['num_elements'].to_numpy()
comp_1_10000 = part_1_10000_df['avg_comparison'].to_numpy()
time_1_10000 = part_1_10000_df['avg_time'].to_numpy()

n_1_5000 = part_1_5000_df['num_elements'].to_numpy()
comp_1_5000 = part_1_5000_df['avg_comparison'].to_numpy()
time_1_5000 = part_1_5000_df['avg_time'].to_numpy()

n_1_1000 = part_1_1000_df['num_elements'].to_numpy()
comp_1_1000 = part_1_1000_df['avg_comparison'].to_numpy()
time_1_1000 = part_1_1000_df['avg_time'].to_numpy()

n_normal = normal_df['num_elements'].to_numpy()
comp_normal = normal_df['avg_comparison'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()

x_axis = range(1,18)

fig, axis = plt.subplots(2, 1, figsize=(10, 7))

fig.suptitle('Comparision and Time Ratio for Normal Distribution')

axis[0].plot(x_axis,comp_1_50000, '.-', label='1/50000')
axis[0].plot(x_axis,comp_1_10000, '.-', label='1/10000')
axis[0].plot(x_axis,comp_1_5000, '.-', label='1/5000')
axis[0].plot(x_axis,comp_1_1000, '.-', label='1/1000')
axis[0].plot(x_axis,comp_normal, '.-', label='Randomized')
axis[0].legend()
axis[0].set_ylabel('comparision')

axis[1].plot(x_axis,time_1_50000, '.-', label='1/50000')
axis[1].plot(x_axis,time_1_10000, '.-', label='1/10000')
axis[1].plot(x_axis,time_1_5000, '.-', label='1/5000')
axis[1].plot(x_axis,time_1_1000, '.-', label='1/1000')
axis[1].plot(x_axis,time_normal, '.-', label = 'Randomized')
axis[1].legend()
axis[1].set_ylabel('time taken')

plt.xlabel(r'n [array size = $2^n$]')

plt.savefig('observation.png')
