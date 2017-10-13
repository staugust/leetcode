import matplotlib.pyplot as plt
import numpy as np
import math

x = np.arange(-5, 5, 0.001);
# y1 = np.sin(x)
# y2 = np.sin(x + math.pi / 3 * 2)
# y3 = np.sin(x - math.pi / 3 * 2)
#
# plt.plot(x, y1)
# plt.plot(x, y2)
# plt.plot(x, y3)
# y4 = y1 * 0.3 + y2 * 0.4 + y3 * 0.3
# plt.plot(x, y4)

arr = [ np.sin(n * x) for n in range(1,100000,2)]
t = np.zeros(len(x))
for tmp in arr:
    t += tmp

print(len(t))
print(len(x))
plt.plot(x, t)
print(t)
plt.show()

