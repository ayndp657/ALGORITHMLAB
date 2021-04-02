from datetime import time
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like

uniform_df = pd.read_csv('MoM_uniform_obs.csv')
normal_df = pd.read_csv('MoM_normal_obs.csv')

n_uniform = uniform_df['arr_size'].to_numpy()
time_uniform = uniform_df['avg_time'].to_numpy()

n_normal = normal_df['arr_size'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()

plt.figure()
plt.plot(n_uniform, time_uniform, label='Uniform')
plt.plot(n_normal, time_normal,  label='Normal')
plt.legend()
plt.xlabel('arr_size (n)')
plt.ylabel('Time in ms')
plt.title('Time vs Array Size in MoM')

plt.savefig('observation.png')
