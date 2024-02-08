import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

num = 100000

obs_df = pd.read_csv('MoMobs.csv')

div_size = obs_df['div_size'].to_numpy()
avg_time = obs_df['avg_time'].to_numpy()

fig = plt.figure('MoM Observation',figsize=(8,8))
plt.plot(div_size,avg_time,'.')
plt.ylabel('time taken in ms')
plt.xlabel('divide size')
plt.title('MoM Observation')
plt.savefig('observationmom.png')

print("done, check photo")
