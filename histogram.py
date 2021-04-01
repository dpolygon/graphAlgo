import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

f = open("data.txt", "r")
size = int(f.readline())
#x = np.array([0] * size)
#for i in x:
#    x[i] = int(f.readline())
x = np.array([0, 1, 1, 2, 3, 2, 2, 2, 2, 1, 1])
fig = plt.gcf()
fig.set_size_inches(16,10)
plt.title('Out-degree Frequency')
plt.xlabel('Out-degree')
plt.ylabel('Frequency')
plt.style.use('ggplot')
plt.hist(x, bins = [0,1,2,3,4])
plt.savefig("histogram.png")