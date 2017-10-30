"""
chapter 6

"""

import cv2
import numpy as np
import os
from matplotlib import pyplot as plt

img = np.zeros([512,512,3], np.uint8)

cv2.line(img, (0,0), (511,511), [255,0,0], 3)
# pts = np.array([[100,50],[200,300],[500,200],[500,100]], np.int32)
pts = np.random.random_integers(0,511, 18)
pts = pts.reshape([3,-1,1,2])
cv2.polylines(img, pts, True, (255,255,0), thickness=5, lineType=cv2.LINE_AA, shift=1)
cv2.putText(img, 'Your Godfather is always your godfather!', (20, 20), fontFace=cv2.FONT_HERSHEY_COMPLEX_SMALL, fontScale=1, color=(128,0,255), bottomLeftOrigin=True)
cv2.putText(img, 'Your Godfather is always your godfather!', (20, 20), fontFace=cv2.FONT_HERSHEY_COMPLEX_SMALL, fontScale=1, color=(0,128,255), bottomLeftOrigin=False)
cv2.imshow('line', img)

cv2.polylines(img, pts.reshape([1,-1,1,2]), True, (255,0,0), thickness=5, lineType=cv2.LINE_AA)

key = cv2.waitKey(0)
while key != ord('q'):
    key = cv2.waitKey(0) & 0xff

cv2.destroyWindow('line')

# img = img[..., ::-1]
plt.imshow(img)
plt.show()



print(img)