#Day 3 Lecture Notes
#

#WORD OF THE DAY HAMBURGER
# Data Structure Operations
#   Sets
#
#
# Why do Data Structures Matter
#   Different data structures have different efficiencies
x = 'Hello! '
y = 'How are you '
z = 'today?'
print(x + y + z)
#   Arrays
#one-dimensional array with 5 elements
array = ["apples","bananas","cucumbers","dates","elderberries"]

# 4 Data Structure Operations
#   Read
#       Looking up value in array and give data at the location
#       Line 9 in Python Fixing The Array Program/pftap.py
#   Search
#       Looking to see if an item is in there and returning index
#       Linear search - when it checks each index in order
#       Maximum number of steps is for N cells linear search takes a maximum of N steps
#       Line 19 in Python Fixing The Array Program/pftap.py
#           Example takes a total of 4 steps
#   Insert
#       Adding a new value to data structure
#       Move items following index to add to one to the right then add item in
#       Efficiency comes down to where we want to insert it
#           Inserting at the end is one step
#           Inserting at beginning or middle we must shift other items
#           Worst case takes up to N+1 steps
#   Delete
#       Removing value from array
#       Delete specific item then move everything to the left one slot
#       Total number of steps is N
#           1 step for delete
#           N-1 steps to shift data
#
#   We measure in steps, not time because the time changes based on hardware
#   also known as measuring it's time complexity
#
#   Operation with one step is the fastest possible
#
#   We must be able to pick between them to determine which is the most efficient
# Sets
#   Array Based Set
#   Does not allow for duplication
#   Reading Complexity 1
#   Searching Complexity N
#   Delete Complextity N
#   Insert Complexity 2N+1
# #
example = set()
example.add('a')
example.add('b')
example.add('c')

print("Example: ",example)

example.add('b')
print("Example: ",example)

# Algorithm
#   Proper selection of algorithm also affects efficiency
#   

#homework reading > searching > insert/delete
#         fastest               slowest