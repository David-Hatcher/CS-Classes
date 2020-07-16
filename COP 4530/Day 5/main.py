# Day 5 Lecture

#WORD OF THE DAY: SHOE

# Speeding Up Your Code
#   How to speed up your code with Big O
#   Binary Search O(log N) vs Linear Search O(N)
#   Compare O of multiple algorithms to decide which is best for your application#
# Bubble Sort
#   Given an array of unsorted numbers, how can we sort them
#       so that they end up in ascending order?
#   2,1,3,5 -> 1,2,3,5 -> 1,2,3,5 -> 1,2,3,5
#   Looks at each item and looks at items until we have a full round of no swaps
#   Passthrough 1
#       4,2,7,1,3 -> 2,4,7,1,3 -> 2,4,1,7,3 -> 2,4,1,3,7 //7 is now in correct position
#       Made one swap go again
#       2,4,1,3,7 -> 2,4,1,3,7 -> 2,1,4,3,7 -> 2,1,3,4,7 //4 now in correct spot
#       Made one swap so go again
#       2,1,3,4,7 -> 1,2,3,4,7 -> 1,2,3,4,7 -> //3 is now in correct spot
#       Made one swap go again
#       1,2,3,4,7 -> 1,2,3,4,7 // bubble sort completed
#       No swaps, we can stop
# #
def bubble_sort(list):
    unsorted_until_index = len(list) - 1 #last index in the list
    sorted = False #set to false initially
    print(list) #show original list
    while not sorted:
        sorted = True #prematurely set to true so if no swaps it stops
        for i in range(unsorted_until_index):#0 - 1 less than the last index so it doesn't go out of bounds
            if list[i] > list[i+1]:
                sorted = False #theres a swap so we have to go again
                list[i], list[i+1] = list[i+1], list[i] #swaps two variables
                print(list) #show list if swap occurs
        unsorted_until_index -= 1 # the largest value is now at the end so shorten the loop

list = [65,55,45,35,25,15,10]
bubble_sort(list)
print(list)
#
# Covered
#   Arrays, Sets, Binary Search, Bubble Sort
# The Efficiency of Bubble Sort
#   10 item array sorted high to low
#   Two steps
#       Comparisons
#           9+8+7+6+5+4+3+2+1=45 Steps
#       Swaps#
#           9+8+7+6+5+4+3+2+1=45 Steps
#       N Data Elements     Max # of steps      N^2
#           5                      20           25
#           10                     90           100
#           20                    380           400
#           40                   1560           1600
#           80                   6380           6400
#   Bubble sort is basically O(N^2)
#       Or quadratic time
# A Quadratic Problem
#   This is O(N^2)
def hasDuplicateValue(array):
    steps = 0
    i = 0
    while(i < len(array)):
        j = 0
        while(j < len(array)):
            steps += 1
            if (i != j) and (array[i] == array[j]):
                print("Steps: ",steps)
                return True
            j += 1
        i += 1
    print("Steps: ",steps)
    return (False)
list = [1,2,3,4,5]
print(list)
print(hasDuplicateValue(list))
#   What qualifies as a step
#       This function has one step, comparison
#       Worst case, array contains no duplicates and must check ALL values before
#           returning false
#       Worst case will compare N^2 times, O(N^2)
# A Linear Solution#
def hasDuplicateVals(array):
    steps = 0
    existingNumbers = []
    largestNum = -1

    for item in array:
        if item > largestNum:
            largestNum = item
            steps += 1

    if(largestNum > len(array)):
        for index in range(largestNum + 1):
            existingNumbers.append(-1)
    else:
        for index in range(len(array) + 1):
            existingNumbers.append(-1)
    print(existingNumbers)

    i = 0
    while(i < len(array)):
        if(existingNumbers[array[i]] == -1):
            existingNumbers[array[i]] = 1
        else:
            print("Steps: ",steps)
            return True
        i += 1
    steps += i
    print("Steps: ",steps)
    print(existingNumbers)
    return False
list = [1,2,3,4,5]
print(hasDuplicateVals(list))
#   Worst Case Function must complete entire loop O(N)
#
#
# Next Class
#   Optimizing Code
#   Selection Sort in Action
#   Selector Sort Implemented#