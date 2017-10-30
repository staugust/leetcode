# learn pyplot

from matplotlib import pyplot as plt
import numpy as np
import os
import cv2

IMGDIR="D:/apidoc/python/OpenCV-3.2.0"
img = cv2.imread(IMGDIR + os.sep + "roi.jpg", )

img = img[:,:,2]
print(img.shape)
img = img.reshape([280,450,1])
img = np.concatenate((img, np.zeros([280,450,2],np.uint8)), axis=2)
img = np.concatenate((img, np.random.randint(0,256,[280,450,1], dtype=np.uint8)), axis=2)
print(img.shape)

plt.figure("six")

plt.subplot(321)
plt.imshow(img)
x = np.arange(0,540,0.1)
y = np.sin(x)
plt.subplot(322)
plt.plot(x, y)

np.random.seed(0)

x, y = np.random.randn(2, 100)
print(x,y)
plt.subplot(323)
plt.xcorr(x, y, usevlines=True, maxlags=50, normed=True, lw=2)

plt.axhline(0, color='black', lw=2)

plt.subplot(324)
plt.acorr(x, usevlines=True, normed=True, maxlags=50, lw=2)
plt.grid(True)
plt.axhline(0, color='black', lw=2)

x = np.random.randn(100)

plt.subplot(325)
plt.acorr(x,usevlines=False, maxlags=10,  normed=True, lw=2)
plt.subplot(326)
plt.acorr(x,usevlines=True, maxlags=50,  normed=False, lw=2)
plt.acorr(x,usevlines=False, maxlags=10,  normed=False, lw=2, figure=plt.figure())

plt.figure(5)
x = np.random.randn(10)
x.sort()
y = np.random.randn(10)
y.sort()
plt.plot(x,y)
plt.arrow(x = 1, y = 1, dx = 1, dy = 20)

plt.show()

# TODO Need to check what xcorr & acorr do.

