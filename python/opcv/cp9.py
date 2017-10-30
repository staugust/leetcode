"""
operate on images
"""
import cv2
import numpy as np
import os

IMGDIR="D:/apidoc/python/OpenCV-3.2.0"
WDIR="D:/tmp"
cv2.namedWindow('fish', cv2.WINDOW_NORMAL)
img = cv2.imread(IMGDIR + os.sep + "roi.jpg", )
print(img.shape)
ball = img[120:180,330:390]
img[220:280,100:160] = ball
print(img.shape)
img = cv2.copyMakeBorder(img, 10,10,10,10,cv2.BORDER_REPLICATE)
print(img.shape)
cv2.imshow('fish', img)
while True:
    key = cv2.waitKey(0)
    if key & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()