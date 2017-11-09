import cv2
from matplotlib import pyplot as plt
import numpy as np

h = np.zeros([255,255]).reshape(-1)
s = np.zeros([255,255]).reshape(-1)
v = np.zeros([255,255,1])
for i in range(len(h)):
    h[i] = (i % 255) / 255.000 * 179.00
    s[i] = 255 - (i / 255) / 255.000 * 255

h = np.uint8(h).reshape([255,255,-1])
s = np.uint8(s).reshape([255,255,-1])
v = np.uint8(v)
print(h.max())
print(s.max())

img = np.concatenate((h,s,v), axis=2)
img[::,::,2] = 160
img = cv2.cvtColor(img, cv2.COLOR_HSV2BGR)
cv2.imshow('img', img)

cv2.waitKey(-1)
