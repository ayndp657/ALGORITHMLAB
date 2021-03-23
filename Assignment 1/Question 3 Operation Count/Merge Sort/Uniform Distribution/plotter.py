import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

obs_df = pd.read_csv('observation.csv')

n = obs_df['num_elements'].to_numpy()
comp = obs_df['avg_comparison'].to_numpy()
time = obs_df['avg_time'].to_numpy()

comp_ratio = comp/(n*np.log2(n))

fig, axis = plt.subplots(2, 1, sharex=True, figsize=(8, 5))

fig.suptitle('Comparision and Time Ratio')

axis[0].plot(comp_ratio, 'o-')
axis[0].set_ylabel(r'$\frac{comp}{n*lgn}$', rotation=0, labelpad=13)

time_ratio = time/(n*np.log2(n))

axis[1].plot(time_ratio, 'o-')
axis[1].set_ylabel(r'$\frac{time}{n*lgn}$', rotation=0, labelpad=13)

plt.xlabel('No. of iterations')

plt.show()
