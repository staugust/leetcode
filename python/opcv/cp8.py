"""
learn to use TrackBar
"""

import cv2
import numpy as np


def nothing(x):
    print(type(x))


img = np.zeros([660,1024,3], np.uint8)
cv2.namedWindow('palette')

cv2.createTrackbar('r', 'palette', 0, 255, nothing)
cv2.createTrackbar('g', 'palette', 0, 255, nothing)
cv2.createTrackbar('b', 'palette', 0, 255, nothing)

switch='0:OFF\n1:ON'
cv2.createTrackbar(switch, 'palette', 0, 1, nothing)

while True:
    cv2.imshow('palette',img)
    key = cv2.waitKey(1)&0xFF
    if key == ord('q'):
        break
    r = cv2.getTrackbarPos('r', 'palette')
    g = cv2.getTrackbarPos('g', 'palette')
    b = cv2.getTrackbarPos('b', 'palette')
    s = cv2.getTrackbarPos(switch, 'palette')
    if s == 0:
        img[:] = 0
    else:
        img[:] = [b,g,r]


cv2.destroyAllWindows()