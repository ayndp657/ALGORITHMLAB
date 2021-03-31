import matplotlib.pyplot as plt
import pandas as pd
from pandas.core.indexing import is_label_like

obs_df = pd.read_csv('MoM_obs.csv')

num = obs_df['num_elements'].to_numpy()

part_3 = obs_df['partition_3'].to_numpy()
part_3_ratio = part_3/num

part_5 = obs_df['partition_5'].to_numpy()
part_5_ratio = part_5/num

part_7 = obs_df['partition_7'].to_numpy()
part_7_ratio = part_7/num

part_9 = obs_df['partition_9'].to_numpy()
part_9_ratio = part_9/num

fig = plt.figure('MoM Observation')
plt.plot(part_3_ratio,label= 'part_3')
plt.plot(part_5_ratio,label= 'part_5')
plt.plot(part_7_ratio,label= 'part_7')
plt.plot(part_9_ratio,label= 'part_9')
plt.legend()
plt.ylabel('time in ms')
plt.xlabel('array size')
plt.title('MoM Observation')
plt.show()