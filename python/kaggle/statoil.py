# https://www.kaggle.com/c/statoil-iceberg-classifier-challenge/data

import json
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import sklearn

TRAIN_FILE = "D:\\kaggle\\statoil-iceberg-classifier-challenge\\train.json"
TEST_FILE = "D:\\kaggle\\statoil-iceberg-classifier-challenge\\test.json"

f = open(TRAIN_FILE,'r')
jf = json.load(f)

f.close()


for item in jf:
    item['id']
    item['band1']
    item['band2']
    item['inc_angle']
    item['is_iceberg']

    
if __name__ == "__main__":
    print(np.__version__)