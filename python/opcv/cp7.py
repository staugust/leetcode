"""
process mouse events
"""

import cv2
import numpy as np

def cbk(event, x, y, flags, param):
    """
    :param event:
    :param x:
    :param y:
    :param flags:
    :param param:
    :return:
    """
    if event == cv2.EVENT_RBUTTONUP:
        color = ([int(i) for i in np.random.randint(0,256,3)])
        print(color)
        cv2.circle(img, (x,y), int(np.random.randint(0,20)), color, -1)


img = np.zeros([1024,1024,3], np.uint8)

cv2.namedWindow('img')
cv2.setMouseCallback('img', cbk)

while True:
    cv2.imshow('img', img)
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break
cv2.destroyWindow('img')