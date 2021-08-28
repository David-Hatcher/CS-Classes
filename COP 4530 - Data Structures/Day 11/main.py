#Lecture 11
#WORD OF THE DAY HAMMER
# HW Music Streaming Application
# Poll to take
# 
# 
# Recursive algorithms for speed
#   Quick Sort
#   Extremely fast sorting algo
# To partition an array to take a "Pivot"
#   Anything udner the pivot goes tot he left
#   Anything over goes to the right
#   
# Quick Sort
#   Partition the array
#   Teach each partition as it's own array
#   And recursively parition the arrays
#   Continue this until you're left with an array with
#       0 or 1 length
#   
# 0,1,2,3,6,5
# 0,1,2   
# Pivot 2 -> no swaps as both 1 and two are less than 2
# next subarray is 0,1
# Pivot 1 -> left pointer points to 0 as well as left pointer
# next subarray is 0, base case, do nothing
# 0,1,2,3,6,5 is the current full array
# next subarray is 6,5
# Pivot 5 -> left and right pointer point to 6
# since 6 is greater than the pivot the left pivot stays
# since left pointer reached right pointer we are done moving pointers
# swap the two pointers
# 1,2,3,5,6
# next subarray is 6, base case, do nothing array sorted
# 
# 
# Efficiency of QuickSort
#   Efficiency of a Partition
#       Two steps
#           Comparisons
#           Swaps
#       Each partition has N Comparisons
#       Each partition has at least 1 swap
#       Most swaps are N/2
#       
#       O(N) steps per partition
#   
# 8 elements * 1.25 steps = 10
# 3 * 1.25 = 3.75
# 4 * 1.25 = 5
# 2 * 1.25 = 2.5
# total = around 21 steps
# Total big O = O(N*logN)
# this is because you're normally
#   breaking the array in half which gives you log N
#   So for N elements you break it in half logN times
# Best case is when pivot ends up in middle
# worst case is when pivot ends up on one end of the array
# Comes out to be (N^2)/2
# but comes out to n^2
# insert n n^2 n^2
# qsort  nlogn nlogn n^2
# 
# 
# Quick Select
#   Hybrid between QuickSort and Binary Search
#   array of 8 values and want to find the second to lowest value
#   O(N) for average scenarios
#   
# Quick sort/select 
#   Both recursive
#   #

