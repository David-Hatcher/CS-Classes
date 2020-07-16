#Lecture 7
#Hash Tables
#Collisions

#WORD OF THE DAY: HOUSE

#Homework #1
#1 Change input to lower case
#2 Split the words into python list
#3 use a set to reduce to unique words
#4 build a data structure that will be a list of lists
#   The lists in the structure will consist of one alphebetic character and then 
#   placeholders for the number of times that character is used as the first letter in the a
#   word, the number of times as the last letter, and the sum of those two values
#5 sum the occurences of the times that each character is used as a first and last character
#6 sort the words based on their combined first and last values
#7 create a list to hold g values, makes it the same size as the number of letters that were found to be
#   first and last letters
#8 Calculate the hash location for each word in the speed and place that word in a hash table
#   use a while loop because you will need to back up when there is a conflict
#9 now read in the second file and perform the lookup function for each word
#
#
#Menu Problems
# menu = [["french fries",0.75],["hamburger",1.5],["soda",0.6]]
#   Searching this takes O(N) steps
#   If it were ordered, it takes O(logN)
#   Hash Table O(1)
#   menu = {
#   "french fries":0.75,
#   "hamburger":2.5,
#   "soda":0.6
#   }#
#Enter The Hash table
#Hashing With hash Functions
# A = 1
# B = 2
# C = 3
# D = 4
# E = 5
# ACE converts to 135
# CAB 312
# 
#Hash Functions
# Process of converting codes into numbers is hashing
# BAD converts to 214
# 2 + 1 + 4 = 7
# or 
# 2 * 1 * 4 = 8
# A has function MUST convert the same string to the same number every time it's applied
#Quickasaurus - Most Popular Synonym
thesarus = {}
#Handling Collisions
# Separate Chaining
#   instead of placing a single value in cell it places a reference to an array where the first value
# word and the second value is it's synonym #
# tehsarus["dab"]
# dab = 4*1*2 = 8
#looks up cell 8
#then does linear search through the inside array to find the correct key to match it's value
#if all data ended up in a single cell the time becomes O(N)
# The Great Balancing act
# How Much Data
# How Many Cells
# Hash Function being used
# A good hash table strikes a balance of avoiding collisions while not consuming lots of memory
# Rule of Thumb: For every seven data elements stored in a hash table, it should have ten cells
# Ratio of Data to Cells is the Load Factor
#   7:10
# #
set = {}
set["apple"] = 1
set["banana"] = 1
set["cucumber"] = 1

#duplicate values would take O(N^2)
set["banana"] = 1
#this has O(1)

#Perfect Hash Functions
#A perfect hash function is one that maps the set of actual keys values to a table without an collisions
#A minimal perfect hash function does so using a table that only has as many slots as there are key values to be hashed
#h(S) = (S.length() + g(S[0]) + g(S[S.length() -1])) % (Size of table)
#3 phases
#computation of the letter freq
#ordering the words
#searching
#Hash tables allow you to build efficient software
#O(1) reads and insertions

#Next
# Code elegence
# Code maintainability
# 
# THings to study
# Next Tuesday in Class will be a review
#   He will point out the specifically importing parts#