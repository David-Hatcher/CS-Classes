''' Imports '''
def warn(*args, **kwargs):
    pass
import warnings

warnings.warn = warn

import numpy as np
import copy as copy

import get_images
import get_landmarks

''' Import classifier '''
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
from sklearn.ensemble import AdaBoostClassifier, RandomForestClassifier
from sklearn.gaussian_process import GaussianProcessClassifier
from sklearn.gaussian_process.kernels import RBF
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import CategoricalNB
from sklearn.naive_bayes import ComplementNB

# NB, SVM, ANN

''' Load the data and their labels '''
img_dir_calTech = 'Caltech Faces Dataset'
img_dir_sof = 'SoF Dataset'
image_directory = img_dir_calTech
X, y = get_images.get_images(image_directory)
print(len(X))

''' Get distances between face landmarks in the images '''
# get_landmarks(images, labels, save_directory="", num_coords=5, to_save=False)
X, y = get_landmarks.get_landmarks(X, y, 'landmarks/', 68, False)
print(len(X))

''' Matching and Decision '''
# create an instance of the classifier
# clf = SVC(kernel='poly',C=20,degree=4)
# clf = KNeighborsClassifier(3)

names = [
    "Nearest Neighbors", 
    # "SVM",
    # "RBF SVM",
    # # "Gaussian Process",
    # "Decision Tree",
    # "Random Forest",
    # "Neural Net",
    # "Gaussian Naive Bayes",
    # "Catagorical Bayes",
    # "Complement Bayes"
    # "AdaBoost",
    # "QDA",
    ]
'''  need to look closer at
    GaussianProcessClassifier(1.0 * RBF(1.0)),
    "RBF SVM",
'''
classifiers = [
    #n_neighbors=5,weights='distance',metric='euclidean',n_jobs=-1
    KNeighborsClassifier(3,n_jobs=-1),
    # SVC(kernel="poly", C=1, degree=6)
    # SVC(gamma=2, C=1),
    # # GaussianProcessClassifier(1.0 * RBF(1.0)),
    # DecisionTreeClassifier(max_depth=6),
    # RandomForestClassifier(max_depth=5, n_estimators=10, max_features=1),
    # MLPClassifier(solver='lbfgs',max_iter=10000), #46%
    # GaussianNB(var_smoothing=1),
    # CategoricalNB(),
    # ComplementNB(),
    # AdaBoostClassifier(),
    # QuadraticDiscriminantAnalysis(),
    ]



for j in range(0,len(names)):
    print()
    print(names[j])
    num_correct = 0
    labels_correct = []
    num_incorrect = 0
    labels_incorrect = []
    Xi = copy.deepcopy(X)
    yi = copy.deepcopy(y)
    clf = classifiers[j]
    for i in range(0, len(yi)):
        query_img = Xi[i, :]
        query_label = yi[i]
        
        template_imgs = np.delete(Xi, i, 0)
        template_labels = np.delete(yi, i)
            
        # Set the appropriate labels
        # 1 is genuine, 0 is impostor
        y_hat = np.zeros(len(template_labels))
        y_hat[template_labels == query_label] = 1 
        y_hat[template_labels != query_label] = 0
        
        clf.fit(template_imgs, y_hat) # Train the classifier
        y_pred = clf.predict(query_img.reshape(1,-1)) # Predict the label of the query
        
        # Gather results
        if y_pred == 1:
            num_correct += 1
            labels_correct.append(query_label)
        else:
            num_incorrect += 1
            labels_incorrect.append(query_label)
            # Print results

    print("Num correct = %d, Num incorrect = %d, Accuracy = %0.2f" 
        % (num_correct, num_incorrect, num_correct/(num_correct+num_incorrect)))    

# labels_i_set = set(labels_incorrect)
# labels_i_count = {}
# for label in labels_i_set:
#     labels_i_count[label] = labels_incorrect.count(label)

# labels_c_set = set(labels_correct)
# labels_c_count = {}
# for label in labels_c_set:
#     labels_c_count[label] = labels_correct.count(label)

# labels_total_counts = []
# labels_full_set = set.union(labels_c_set,labels_i_set)
# for label in labels_full_set:
#     correct_count, incorrect_count = 0, 0
#     if(label in labels_c_count):
#         correct_count = labels_c_count[label]
#     if(label in labels_i_count):
#         incorrect_count = labels_i_count[label]
#     labels_total_counts.append((label,correct_count,incorrect_count,correct_count/(correct_count + incorrect_count)))

# labels_total_counts.sort(key =  lambda tuple: tuple[3])

# print(labels_total_counts)

# Print results
# print()
# print("Num correct = %d, Num incorrect = %d, Accuracy = %0.2f" 
#       % (num_correct, num_incorrect, num_correct/(num_correct+num_incorrect)))    
    
    