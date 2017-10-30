import numpy as np
import cv2
import os
import matplotlib.pyplot as plt
IMGDIR="D:/apidoc/python/OpenCV-3.2.0"
WDIR="D:/tmp"

cap = cv2.VideoCapture("C:/TDDOWNLOAD/catch.mkv")

print(cap.get(cv2.CAP_PROP_FPS))
while True:
    ret, frame = cap.read()
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break



cap.release()
cv2.destroyAllWindows()

cp = cv2.VideoCapture(0)
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter(WDIR+'/'+'test.avi', fourcc, 20.0, (640,480))

while(cp.isOpened()):
    ret, frame = cap.read()
    if ret == True:
        frame = cv2.flip(frame, 0)
        out.write(frame)
          