import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

uniform_df = pd.read_csv('merge_uniform_obs.csv')
normal_df = pd.read_csv('merge_normal_obs.csv')

n_uniform = uniform_df['num_elements'].to_numpy()
comp_uniform = uniform_df['avg_comparison'].to_numpy()
time_uniform = uniform_df['avg_time'].to_numpy()
comp_ratio_uniform = comp_uniform/(n_uniform*np.log2(n_uniform))
time_ratio_uniform = time_uniform/(n_uniform*np.log2(n_uniform))

n_normal = normal_df['num_elements'].to_numpy()
comp_normal = normal_df['avg_comparison'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()
comp_ratio_normal = comp_normal/(n_normal*np.log2(n_normal))
time_ratio_normal = time_normal/(n_normal*np.log2(n_normal))


fig, axis = plt.subplots(2, 1, figsize=(10, 7))

fig.suptitle('Comparision and Time Ratio')

axis[0].plot(comp_ratio_uniform, 'o-', label='Uniform')
axis[0].plot(comp_ratio_normal, 'o--', label='Normal')
axis[0].legend()
axis[0].set_ylabel(r'$\frac{comp}{n*lgn}$', rotation=0, labelpad=13)

axis[1].plot(time_ratio_uniform, 'o-', label='Uniform')
axis[1].plot(time_ratio_normal, 'o--', label = 'Normal')
axis[1].legend()
axis[1].set_ylabel(r'$\frac{time}{n*lgn}$', rotation=0, labelpad=13)

plt.xlabel(r'n [array size = $2^n$]')

plt.show()
plt.savefig('observation.png')
