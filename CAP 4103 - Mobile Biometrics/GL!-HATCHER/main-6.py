from sklearn.datasets import load_digits
import matplotlib.pyplot as plt
import numpy as np

digits = load_digits()

fig = plt.figure(figsize=(15,7.5))
plt.gray()

rows = 2
columns = 5

for i in range(10):
    print(digits.images[np.random.randint(0,len(digits.images))])

# Creating Plot of 10 random images
for i in  range(1,11):
    fig.add_subplot(rows,columns,i)
    plt.imshow(digits.images[np.random.randint(0,len(digits.images))])

plt.show()