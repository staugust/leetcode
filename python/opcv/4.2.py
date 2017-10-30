# display an image

import numpy as np
import cv2
import os
from matplotlib import pyplot as plt

IMGDIR="D:/apidoc/python/OpenCV-3.2.0"
WDIR="D:/tmp"

cv2.namedWindow('fish', cv2.WINDOW_NORMAL)
image = cv2.imread(IMGDIR + os.sep + "a15.jpg", )
cv2.imshow('fish', image)
cv2.imshow('sss', image)
key = cv2.waitKey(0)
b,g,r = cv2.split(image)
img2 = cv2.merge([r,g,b])
img2 = image[:,:,::-1]
img2 = image[..., ::-1]
while key:
    print(key)
    key = cv2.waitKey(0)
cv2.destroyAllWindows()

plt.imshow(img2)
plt.show()

img3 = plt.imread(IMGDIR + os.sep + "a15.jpg", )
cv2.imshow('fish', img3)

key = cv2.waitKey(0)
while key:
    print(key)
    key = cv2.waitKey(0)
cv2.destroyAllWindows()

