import numpy as np
import pandas as pd
import sklearn
from sklearn import datasets
import matplotlib.pyplot as plt
import tensorflow as tf
import re

TRAIN_PATH="D:\\kaggle\\titanic\\train.csv"
TEST_PATH="D:\\kaggle\\titanic\\test.csv"
GENDER_PATH="D:\\kaggle\\titanic\\gender_submission.csv"

# f = open("D:\\kaggle\\titanic\\ptrain.csv","w+")
#
# for line in open(TRAIN_PATH, "r"):
#     while line.find(",,") != -1:
#         line = line.replace(",,",",0,")
#     s = line.find('"')
#     e = line.find('"', s + 1)
#     if (s != -1) and (e != -1):
#         line = line[:s] + "nobody" + line[e+1:]
#     f.write(line)
# f.flush()
# f.close()

# data = np.loadtxt("D:\\kaggle\\titanic\\ptrain.csv", delimiter=",", skiprows=1, usecols=(0,1,2,4,5,6,7,9,10,11),
#                   converters={0: lambda x: int(x.strip()),
#                               1: lambda x: str(x.strip()),
#                               3: lambda x: str(x.strip()),
#                               4: lambda x: str(x.strip()),
#                               5: lambda x: str(x.strip()),
#                               6: lambda x: str(x.strip()),
#                               7: lambda x: str(x.strip()),
#                               8: lambda x: str(x.strip()),
#                               9: lambda x: str(x.strip()),
#                               10: lambda x: str(x.strip()),
#                               11: lambda x: str(x.strip()),
#                               })
# labels = data[0]
# data = data[1:]
#
# data = np.delete(data, obj=3, axis=1)  # remove name
# data = np.delete(data, obj=7, axis=1)  # remove Ticket
#
# np.savetxt("D:\\kaggle\\titanic\\processed.csv", data, fmt="%s",delimiter=',')
#
# np.ndarray.max()
# np.amax()

e = pd.read_csv("D:\\kaggle\\titanic\\ptrain.csv", sep=',')
print(e.shape)

print(e.head(1))
print(type(e))