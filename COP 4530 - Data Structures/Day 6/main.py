#Day 6 Lecture
#
#
#   WORD OF THE DAY: PIZZA
#Optimizing Code
#   With and Without Big O
#   Big O may describe two algos as the same but one is FASTER#
#Selection Sort
#   2,6,1,3 -> 1,6,2,3
#   1,6,2,3 -> 1,2,6,3
#   1,2,6,3 -> 1,2,3,6#
def selectionSortDavid(array):
    for i in range(len(array)):
        lowestIndex = i
        for j in range(i + 1,len(array)):
            if(array[j] < array[lowestIndex]):
                lowestIndex = j
        if(lowestIndex != i):
            array[i], array[lowestIndex] = array[lowestIndex], array[i]
array = [4,2,7,1,3]
print(array)
selectionSortDavid(array)
print(array)
#Insertion Sort
#   Removals,Comparisons,Shifts, and Insertions
#   Comparisons: Comparing two numbers
#       Array with 5 elements
#       1 + 2 + 3 + 4 = 10
#       Approx (N^2)/2 Comparisons
#   Shifts: Moving a value one cell to right
#       As many shifts as comparisons in worst case
#       (N^2)/2 Shifts
#   Removals
#       N - 1 removals
#   Insertions: same as removals
#       N - 1 removals
#   Total N^2 + 2N - 2 steps
#       Ignore constants
#       Big O only takes the highest order
#       Thus this has O(N^2) complexity
#Although bubble sort and and selection sort
#   Worst case:
#       Selection sort is faster
#   Average case:
#       Insertion Sort is faster
#       Insertion takes about (N^2)/2
#
#Insertion Sort varies greatly depending on the randomness of the data
#   Worst Average Best
#     N^2  (N^2)/2   N
#   This is because selection doesn't have the ability to end a passthrough early, same thing as bubble sort
#Which is better? It Depends.
# If mostly sorted in reverse order, Selection Sort
# If mostly random, Insertion sort
# If no idea, the either is good#
def insertion_sort(array):
    for index in range(1,len(array)):
        position = index
        temp_value = array[index]

        while position > 0 and array[position - 1] > temp_value:
            array[position] = array[position -1]
            position -= 1
        array[position] = temp_value
    return array
list = [5,4,2,1,3]
print(list)
print(insertion_sort(list))

#Intersection
def intersection(first_array,second_array):
    result = []
    i = 0
    while(i < len(first_array)):
        j = 0
        while(j < len(second_array)):
            if(first_array[i] == second_array[j]):
                result.append(first_array[i])
                #You can actually stop after this
            j += 1
        i += 1
    return result

a = [3,1,4,2]
b = [4,5,3,6]
print(intersection(a,b))

#Comparisons
#   If arrays are equal size there are n^2 comparisons
#   Basically N * M
#   O(N^2) or O(N*M)
#
#Can we make it Better?
# Yes! See line 79#
def intersection(first_array,second_array):
    result = []
    i = 0
    while(i < len(first_array)):
        j = 0
        while(j < len(second_array)):
            if(first_array[i] == second_array[j]):
                result.append(first_array[i])
                break
            j += 1
        i += 1
    return result

a = [3,1,4,2]
b = [4,5,3,6]
print(intersection(a,b))
#Wrapping Up
#   Being able to discern between: Best, Average, and Worst Case
#   While it's good to be ready for worst case, average is what will happen
#       most of the time
#Next Time: Choose Between Two Data Structures
#Menu Problems
#Enter The Hash Table
#Hashing with Hash Functions
#Building a Thesaurus
#Dealing with Collisions#