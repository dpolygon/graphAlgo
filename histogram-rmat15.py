import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

x = []
biggestBin = 0

with open('data.txt') as f:
    size = int(f.readline())
    for line in f:
        x.append(int(line))

        if int(line) > biggestBin:
            biggestBin = int(line)
    biggestBin = biggestBin + 1

fig = plt.gcf()
fig.set_size_inches(16,10)
plt.title('Out-degree Frequency')
plt.xlabel('Out-degree')
plt.ylabel('Frequency')
plt.style.use('ggplot')

bins = 10**(np.arange(0,6))

plt.xscale('log')
plt.hist(x, bins = bins)
plt.savefig("histogram.png")