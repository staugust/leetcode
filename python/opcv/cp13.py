# image process
import cv2
import os
import numpy as np

IMGDIR="D:/apidoc/python/OpenCV-3.2.0"
img = cv2.imread(IMGDIR + os.sep + "roi.jpg", )

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

lower_blue = np.array([110,50,50])
upper_blue = np.array([130,255,255])

mask = cv2.inRange(hsv, lowerb=lower_blue, upperb=upper_blue)
for line in mask:
    print(line)
res = cv2.bitwise_and(img, img, mask=mask)

cv2.imshow('orig', img)
cv2.imshow('mask', mask)
cv2.imshow('res', res)

k = cv2.waitKey(0)
while k != ord('q'):
    k = cv2.waitKey(0) & 0xFF

cv2.destroyAllWindows()