import matplotlib.pyplot as plt
from numpy import genfromtxt
data = genfromtxt('Output.csv',delimiter=',', skip_footer=4986)
# print len(data)
data1 = genfromtxt('Samples.csv',delimiter=',', skip_footer=4986)
f, (ax1, ax2) = plt.subplots(2, sharex = True)
# ax2.scatter(range(200),data1)
ax1.plot(data)
ax2.plot(data1)
plt.show()
