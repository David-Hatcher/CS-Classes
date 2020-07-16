#Day 4 Lecture: Binary search, Big O Notation

# WORD OF THE DAY : TRUCK
#
# Ordered Arrays
#   Insert
#       Values are always kept in order
#       Checks value at each index against the value to insert and determines if it goes to left or right
#   Search
#       Checks the same but if it finds a value that's higher it can stop as it's not in the array
#       [3,17,75,80,202]
#       If we look for 22 then when we hit 75 we can stop as we know it's not in there
#
def linear_search(array,value):

#Iterate through every element in the array
    for element in array:
#If we find the value, return the value
        if element == value:
            return value
#If we find a number that's higher then we know it's not there
        elif element > value:
            break
#If it's not there return none
    return None

array = [3,17,75,80,202]
print("Result of search = ", linear_search(array,100))
#
# Algorithms
#   Linear Search
#   Binary Search#
# Binary Search
#   Cut the array in half determine which half has the number
#   Repeat until you're left with an array with only 1 number#
# Binary Search vs Linear Search
#   With order arrays of small size not a big gain
#   But with larger arrays it takes much less time
#   Array size 3, steps = 2
#   Array size 7, steps = 3
#   Array size 15, steps = 4
#   Every time we double the number of items the steps increases by just 1
#   10,000 - 13 steps
#   1,000,000 - 20 steps
#
# Big O Notation
#   Order of the function, growth rate
#   Reading from array = O(1), 1 step
#   Insertion or Deletion at END of array is also O(1)
#   Linear Search = O(N), takes up to N steps#
# Constant Time vs. Linear Time
#   Big O answers "How does the number of steps change as the data increases?"
#   O(n) will increase by 1 for each item added to the array
#   O(1) will always stay the same no matter how big the array gets
#   O(1) is Constant Time, O(N) is Linear Time
#   An Algorithm can be described as O(1) even if it takes more than one step
#       as long as the number of steps doesn't change
#   O(1) is the way to describe any algorithm whose number of steps doesn't change
#       no matter how many items you add
#   A constant 100 step algorithm can be described as O(1)
#   A constant 100 step algorithm can be said to be more efficient than an O(N)
#   Because there is always some amount of data that will turn the tides and make the O(N)
#       take more steps than the O(1) it is always said to be more efficient
#   Linear Search is O(1) in its best case and O(N) in its worst
#   Big O notation typically describes the WORST CASE SCENARIO
#   Binary Search isn't O(1) or O(N)
#       Binary Search has a time complexity O(log N)#
# A Review of Logarithms
#   Inverse of exponent
#   2^3 = 2 * 2 * 2 = 8
#   Log2(8) = 3
#   How many times to mulitple the base by it self to get the value
#   Log2(8) could be described as 8 / 2 / 2 / 2 = 1, how many times did we need to divide
#       to get to 1


# O(log N) Explained
#   O(log N) = O(log2(N))
#   If we had 8 elements and the algo has complexity of O(log N) then it would take 3 steps#
# Practical Python Examples
things = ['apples','baboons','cribs','dulcimers']
for thing in things:
    print("Here's a thing: {0}".format(thing))
#   O(N) ^^
def is_prime(number):
    for i in range(2,number):
        if number % i == 0:
            return False
    return True
#   O(N) ^^