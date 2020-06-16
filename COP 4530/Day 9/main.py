# Day 9 lecture notes
#   Review
# The Secret of the Red Dot
#   Slides with red dot are MORE IMPORTANT
#       than the other slides
# Arrays,set,binsearch,bub sort, sel sort, insert sort, hash, stakcs, queues, recursion
# Ararys
#   How the work
#   List of objects
# Operations
#   Read
#   Search
#   Insert
#   Delete
# Key Concept
#   Speed of an opertions
#       Measured in steps
# Search
#   Looking for something in a DS
#   How many steps to a search
#       Linear Search - N
# Insert
#   End is 1 Steps
#   IN middle, have to shift everyhing
#   Becomes N at worst
# Delete
#   At end is 1 Step
#   Anywhere else N steps worst
# Set
#   DS that does not allow duplicates
#   Reading
#   Insert takes 2N + 1 steps
#       Must ensure it's not already there
# Ordered array
#   Same as array but it's values are kept in order
#   Searching takes log N by using binary search
# Big O Notation
#   Always represents the growth rate of the algorithm
#   Read O(1)
#   Search O(N)
#   Binary Search O(logN)
# Bubble Sort
#   Puts the highest in the right hand side on first pass
#   if it doesn't need to swap in a passthrough it stops
#       as the array is sorted
#   Efficiency O(N^2)
# Opimizing Code W or W/O Big O
# Selection Sort
#   it finds smallest number then swaps it with the first
#       number
# Insertion Sort
# In worst case, all algo are pretty bad
# But average case 
#   Insertion is good for MOSTLY sorted data
#   Fully Random, doesn't matter
#   If it's in reverse order, Selection Sort is best
# Hash Tables
#   key,pair values
#   Does REALLY REALLY fast reading, O(1)
#   Dealing with Collisions
#       THis is when you try to add data to a cell that is taken
#       You can but a dict in a slot to store multiples
#   Worst case performance is O(N)
#       Everything in one slot
#   Three Factors
#       How much data
#       How many cells avail in table
#       What hash function is being used
# Stacks and Queues
#   Temp data
#   Stacks LIFO
#       Push to stack - end
#       Pop from stack - end#
#   Queue FIFO
#       Push to queue - end
#       Pop from queue - front
# Recursion
#   a function that calls itself
#   find base case, go up from there
#   Base Case
#       The value in which a method will not recurse
# Stack Overflow
#   When you hit in infinite loop with a recursive algorithm#