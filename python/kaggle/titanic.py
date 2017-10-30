import numpy as np
import pandas as pd
import sklearn
from sklearn import datasets
import matplotlib.pyplot as plt
import tensorflow as tf
import re

from sklearn import linear_model

TRAIN_PATH = "D:\\kaggle\\titanic\\train.csv"
TEST_PATH = "D:\\kaggle\\titanic\\test.csv"
GENDER_PATH = "D:\\kaggle\\titanic\\gender_submission.csv"

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

mp = {'S':1,'C':2,'Q':3}

def tfm(df):
    """
    :type df: pandas.core.frame.DataFrame
    :return: numpy.ndarray
    """
    df.fillna(value=0.0, inplace=True)
    X = np.zeros([len(df), 7], dtype=np.float64)
    for i in range(len(df)):
        X[i][0] = df.Pclass[i]
        X[i][1] = 1 if df.Sex[i] == 'male' else 0
        X[i][2] = df.Age[i]
        X[i][3] = df.SibSp[i]
        X[i][4] = df.Parch[i]
        X[i][5] = df.Fare[i]
        X[i][6] = mp[df.Embarked[i]] if df.Embarked[i] in mp else 0
    return X


df = pd.read_csv(TRAIN_PATH, sep=',', na_values=0.0)
df.fillna(value=0.0, inplace=True)
model = linear_model.LinearRegression()
#  'Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare', 'Embarked'
X = np.zeros([len(df), 7], dtype=np.float64)
for i in range(len(df)):
    X[i][0] = df.Pclass[i]
    X[i][1] = 1 if df.Sex[i] == 'male' else 0
    X[i][2] = df.Age[i]
    X[i][3] = df.SibSp[i]
    X[i][4] = df.Parch[i]
    X[i][5] = df.Fare[i]
    X[i][6] = mp[df.Embarked[i]] if df.Embarked[i] in mp else 0


# 'Survived'
y = np.array(df.Survived.tolist())

model.fit(X, y)

pdf = pd.read_csv(TEST_PATH)
parr = tfm(pdf)

res = model.predict(parr)

THRESHOLD = 0.35

pRes = [1 if i > 0.35 else 0 for i in res]

pdf['Survived'] = pRes

print(pdf)
pdf.to_csv('D:\\kaggle\\titanic\\res.csv', columns=['PassengerId','Survived'], index=False)

