import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

obs_df = pd.read_csv('observation.csv')

# plt.plot(obs_df['num_elements'],obs_df['avg_comparison'],'o')
plt.scatter(obs_df['num_elements'],obs_df['avg_comparison'])


x = np.linspace(1, obs_df['num_elements'].max())

# for c in np.linspace(3.8,3.9,5):
y = 3.885*x * np.log2(x)
plt.plot(x, y,'r')


plt.show()
