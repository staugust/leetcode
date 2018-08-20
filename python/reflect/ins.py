import inspect
import sklearn.linear_model
import json
mth = getattr(sklearn.linear_model.LinearRegression,'__init__')

# mth = getattr(sklearn.linear_model.LinearRegression, 'fit')

sig = inspect.signature(mth)

params = sig.parameters

inspect.Parameter

for k, v in params.items():
    print("{} --> {} {} {}".format(v.annotation, v.name, v.default, v.kind))
    print(type(v.default))

print(type(sig))