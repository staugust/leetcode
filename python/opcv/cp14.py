# transform an image

import cv2
import os
import numpy as np

IMGDIR="D:/apidoc/python/OpenCV-3.2.0"

# img = np.random.randint(0,256, [240,512,3], dtype=np.uint8)
arr = np.arange(0,256,16,dtype=np.uint8)
img = []
for r in range(len(arr)):
    for j in range(len(arr)):
        for k in range(len(arr)):
            img.append([arr[r], arr[j], arr[k]] * 32)

img = np.array(img , dtype=np.uint8)

img = img.reshape([256,-1,3])
print(img.shape)
cv2.imshow('hah',img)

k = cv2.waitKey(0)
while k != ord('q'):
    k = cv2.waitKey(0) & 0xFF

cv2.destroyAllWindows()