''' Imports '''
def warn(*args, **kwargs):
    pass
import warnings
warnings.warn = warn

import get_images
import get_landmarks
import performance_plots

from sklearn.multiclass import OneVsRestClassifier as ORC
from sklearn.model_selection import train_test_split
import pandas as pd

import matplotlib.pyplot as plt

''' Import classifier '''
from sklearn.neighbors import KNeighborsClassifier as knn

''' Load the data and their labels '''
image_directory = 'Caltech Faces Dataset'
projOneDir = 'Project 1 Database/'
projectOneFemale = projOneDir + '00 Female'
projectOneMale = projOneDir + '00 Male'
projectOneAll = projOneDir + 'All'
X, y = get_images.get_images(projectOneAll)
print(len(X))

''' Get distances between face landmarks in the images '''
X, y = get_landmarks.get_landmarks(X, y, 'landmarks/', 68, False)

for k in range(1,44,2):
    ''' Matching and Decision '''
    clf = ORC(knn(n_neighbors=k))
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=42)
    clf.fit(X_train, y_train)

    matching_scores = clf.predict_proba(X_test)

    gen_scores = []
    imp_scores = []
    classes = clf.classes_
    matching_scores = pd.DataFrame(matching_scores, columns=classes)

    for i in range(len(y_test)):    
        scores = matching_scores.loc[i]
        mask = scores.index.isin([y_test[i]])
        gen_scores.extend(scores[mask])
        imp_scores.extend(scores[~mask])

    performance_plots.performance(gen_scores, imp_scores, 'kNN  k = ' + str(k), 500)


plt.show()
    
    
