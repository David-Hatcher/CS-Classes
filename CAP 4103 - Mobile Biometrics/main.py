import numpy as np
import pandas as pd
from sklearn.svm import SVC as svc
from sklearn.feature_selection import VarianceThreshold as vt
from sklearn.metrics import accuracy_score as ac
from sklearn.model_selection import train_test_split as tts

df = pd.read_excel('dataset.xlsx')
df.dropna(inplace=True)
y = df['Subject']
df.drop('Subject',axis=1,inplace=True)

#adding random state for reproducable values to see if the thresholds improve the score
X_train, X_test, y_train, y_test = tts(df, y, test_size=0.25,random_state=42)

clf = svc(kernel="linear", C=0.025)
clf.fit(X_train, y_train)
pred = clf.predict(X_test)
accScore = ac(y_test,pred)
print("Accuracy score = ", accScore)

total, count = 0,0
varianceDict = df.var()
for key in varianceDict.keys():
    total += varianceDict[key]
    count += 1
n = (total / count) / 10
print("n = ",n)
t = 0
while t <=  total / count:
    #adding random state for reproducable values to see if the thresholds improve the score
    X_train, X_test, y_train, y_test = tts(df, y, test_size=0.25,random_state=42)
    selector = vt(threshold=t)
    _ = selector.fit(X_train)
    mask = selector.get_support()
    X_train = X_train.loc[:,mask]
    X_test = X_test.loc[:,mask]
    clf = svc(kernel="linear", C=0.025)
    clf.fit(X_train, y_train)
    pred = clf.predict(X_test)
    accScore = ac(y_test,pred)
    print("Accuracy Score for t = %.2f" % t, "- %.2f" % accScore)
    t += n