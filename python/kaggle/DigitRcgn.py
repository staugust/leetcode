# https://www.kaggle.com/c/digit-recognizer

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier
import nltk
import os
import cv2

TRAIN_PATH='D:/kaggle/Digit Recognizer/train.csv'
TEST_PATH = 'D:/kaggle/Digit Recognizer/test.csv'

tdf = pd.read_csv(TRAIN_PATH)
X = tdf.drop(['label'], axis=1)
model = RandomForestClassifier()
model.fit(tdf, tdf.label)

