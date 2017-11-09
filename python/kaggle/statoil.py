# https://www.kaggle.com/c/statoil-iceberg-classifier-challenge/data

import json
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import sklearn
import cv2

TRAIN_FILE = "D:\\kaggle\\statoil-iceberg-classifier-challenge\\train.json"
TEST_FILE = "D:\\kaggle\\statoil-iceberg-classifier-challenge\\test.json"

f = open(TRAIN_FILE,'r')
jf = json.load(f)

f.close()

ids = np.array([item['id'] for item in jf])
band1 = np.array([item['band_1'] for item in jf]).reshape([1604, 75, -1])
band2 = np.array([item['band_2'] for item in jf]).reshape([1604, 75, -1])
angles = np.array([item['inc_angle'] for item in jf])
label = np.array([item['is_iceberg'] for item in jf])

tb1 = np.array((band1 + 46) * 3, dtype=np.uint8)
tb2 = np.array((band2 + 46) * 3, dtype=np.uint8)


if __name__ == "__main__":
    for i in range(len(tb1)):
        cv2.imshow('img1', tb1[i, :, :])
        cv2.imshow('img2', tb2[i, :, :])
        print(angles[i], label[i])
        key = cv2.waitKey(0)
        cv2.destroyAllWindows()