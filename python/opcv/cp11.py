# performance related topics

import cv2
import numpy as np
import os
import timeit

print(cv2.useOptimized())

IMGDIR="D:/apidoc/python/OpenCV-3.2.0"
cv2.namedWindow('fish', cv2.WINDOW_NORMAL)
img = cv2.imread(IMGDIR + os.sep + "roi.jpg", )
cv2.setUseOptimized(False)
t1 = cv2.getTickCount()
cv2.medianBlur(img,49)
t2 = cv2.getTickCount()

cv2.setUseOptimized(False)
cv2.medianBlur(img,49)
cv2.setUseOptimized(True)
t3 = cv2.getTickCount()
cv2.medianBlur(img,49)
t4 = cv2.getTickCount()

tm = timeit.Timer("cv2.medianBlur(img,49)", 'import cv2\nimport os\nIMGDIR="D:/apidoc/python/OpenCV-3.2.0"\nimg = cv2.imread(IMGDIR + os.sep + "roi.jpg", )\ncv2.setUseOptimized(False)').timeit(20)
print(tm)
tm = timeit.Timer("cv2.medianBlur(img,49)", 'import cv2\nimport os\nIMGDIR="D:/apidoc/python/OpenCV-3.2.0"\nimg = cv2.imread(IMGDIR + os.sep + "roi.jpg", )\ncv2.setUseOptimized(True)').timeit(20)
print(tm)
print(t2 - t1, t3 - t2, t4 - t3)
