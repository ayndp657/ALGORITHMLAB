import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like

uniform_df = pd.read_csv('bucket_uniform_obs.csv')
normal_df = pd.read_csv('bucket_normal_obs.csv')

n_uniform = uniform_df['num_elements'].to_numpy()
comp_uniform = uniform_df['avg_comparison'].to_numpy()
time_uniform = uniform_df['avg_time'].to_numpy()
comp_ratio_uniform = comp_uniform/(n_uniform)
time_ratio_uniform = time_uniform/(n_uniform)

n_normal = normal_df['num_elements'].to_numpy()
comp_normal = normal_df['avg_comparison'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()
comp_ratio_normal = comp_normal/(n_normal)
time_ratio_normal = time_normal/(n_normal)


plt.title('Comparision and Time Ratio')
plt.plot(n_uniform,time_uniform, 'o-', label='Uniform')
plt.plot(n_normal,time_normal, 'o-', label = 'Normal')
plt.legend()
plt.ylabel('time(ms)')

plt.xlabel('array size(n)')

plt.savefig('observation.png')