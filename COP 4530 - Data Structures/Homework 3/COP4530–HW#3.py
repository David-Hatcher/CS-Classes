from timeit import default_timer as timer
import sys
#####################
#  Global Variables #
#####################
leftCounter = 0
rightCounter = 0
largestValue = ''
smallestValue = ''
nodeCount = 0

#
# COP 4930 - Homework #3
# Binary Tree Mirroring
#

class Node:

    def __init__(self,name):
        self.ID = name
        self.left = None
        self.right = None
        self.parent = None
    #######################################
    #           Code I Added              #
    #######################################

    # printTree recursively prints out all of the tree noes
    # with the correct indentation, base case being that it
    # reaches a node with no left or right values
    def printTree(self,num = 0,side = ''):
        if(num == 0):
            print(" {}".format(self.ID))
        else:
            print("{0} {1} {2}".format(side,"   "*num,self.ID)) # 4 spaces * num argument and print node ID
        if(self.left != None): # Check if left has a value
            self.left.printTree(num + 1,'L:') # Calling itself on the left node, and incrementing num
        if(self.right != None): # Check if right has a value
            self.right.printTree(num + 1,'R:') # Calling itself on the right node, ad incrementing num

    # mirror will recrusively swap all the left nodes with the right nodes and call
    # itself on the next nodes in the tree, the base case being that it reaches a node with
    # no left or right values
    def mirror(self):
        self.left, self.right = self.right, self.left # Swapping left and right pointers
        # print("Parent: ",self.ID) # Printing the parent, which for the left and rights is this node
        # if(self.left != None): # Check if left has a pointer
        #     print("Left: ",self.left.ID) # Printing the left node name
        # if(self.right != None): # Check if right has a pointer
        #     print("Right: ",self.right.ID) # Printing the right node name
        # print() # putting a space afterwards
        if(self.right != None): # Checking if there is a right node
            self.right.mirror() # Recursively calling itself on the right node
        if(self.left != None): # Checking if there is a left node
            self.left.mirror() # Recurisvely calling itself ont the left node

    # countNodes takes a boolean representing if the current node is the root of the tree, this is fully
    # recursive, the base case being that it reaches a node with no left or right values
    def countNodes(self,onRoot,currentSide = ''):
        global rightCounter, leftCounter, nodeCount # Setting global variables to be updated
        nodeCount += 1 # found a node so increment counter
        if(currentSide == 'Right'): # Checking if we're on the right side of the tree
            rightCounter += 1 # Right side node found, incrementing counter
        if(currentSide == 'Left'): # Checking if we're on the left side of the tree
            leftCounter += 1 # Left side node found incrementing counter
        if(onRoot == True): # Checking to see if we're on the root
            currentSide = 'Right' # If not on the root we're setting the current side to right
        if(self.right != None): # Checking to see if there is a right side node, base case
            self.right.countNodes(False,currentSide) # found right side node, recursive call on this function
            # currentSide being passed as it is right side, used for counting
        if(onRoot == True): # Checking if we're on root node
            currentSide = 'Left' # If we're on root node set currentSide to left as we're done with the right side
        if(self.left != None): # Checking if there is a left node, base case
            self.left.countNodes(False,currentSide) # found left side node, recursive call on this function
            # currentSide being passed as it is left side, used for counting

    # findSmallestAndLargest is used to traverse the tree and find the smallest and largest values
    # this is fully recursive, the base case being that it reaches a node with no left or right values
    def findSmallestAndLargest(self):
        global smallestValue, largestValue # Setting global variables to be updated
        if(self.ID < smallestValue): # Checking if current nodes value is less than current smallest
            smallestValue = self.ID # Found new smallest so set it
        if(self.ID > largestValue): # Checking if current nodes value is greater than largest
            largestValue = self.ID # Found new largest so set it
        if(self.right != None): # Checking for right side node, base case
            self.right.findSmallestAndLargest() # Recursive call to this function on the right side node
        if(self.left != None): # Checking for left side node, base case
            self.left.findSmallestAndLargest() # Recursive call to this function on left side node


    #######################################
    #           End Code I Added          #
    #######################################


#
# Function to create and label all of the nodes in the tree
#

def labelTree(treeNode):
    global treeDepth
    global treeLoc

    treeDepth += 1 # we are now one level deeper in the tree
    # print("\nParent: ",treeNode.ID)

    treeNode.parent = treeLoc # set parent node to the previous node processed
    treeLoc = treeNode # set the tree pointer node to the node passed to the function
    # print("\nParent: {}".format(treeLoc.ID))
    # print("I have set the parent for {0} to {1}".format(treeLoc.ID, treeNode.parent.ID))

    if (treeDepth < 6 and (len(nodeNames) > 0)):

        treeLoc.left  = Node(nodeNames.pop(0)) # create left child
        # print("Left : ",treeLoc.left.ID)
        if (len(nodeNames) > 0):
            treeLoc.right = Node(nodeNames.pop(0)) # create right child
            # print("Right: ",treeLoc.right.ID)

        if (treeLoc.left != None):
            labelTree(treeLoc.left)  # preocess the left hand side using recursion
        if (treeLoc.right != None):
            labelTree(treeLoc.right) # process the right hand side using recursion


    treeDepth -= 1 # we are now moving one level up in the tree when we return
    treeLoc = treeLoc.parent  # done with this set of children, reset current tree pointer to parent node


    return




# start timer
start = timer()

#
# Parse the node name file and load the names into a list
#

if len(sys.argv) != 2:
    raise ValueError('Please provide a file name.')

sys.argv[0] = sys.argv[0][0:len(sys.argv[0]) - sys.argv[0][::-1].find('/')]

inputFile1 = sys.argv[1]

# print("\nThe file that will be used for input is {0}".format(sys.argv[1]))

infile1 = open(inputFile1,"r")

nodeNames = infile1.readline().rstrip().split()


#
# Create the binary tree
#

treeDepth = 1
treeLoc = None

#
# Create root node of tree
#

root = Node(nodeNames.pop(0))
treeLoc = root


#
# Create the rest of tree and label each of the nodes
#

# print("\nBuilding the tree:\n")
labelTree(root)

# Setting initial values for comparison of largest and smallest values in tree
largestValue = root.ID
smallestValue = root.ID

# Counting total nodes and left/right side nodes
root.countNodes(True)

# Finding smallest and largest values on nodes
root.findSmallestAndLargest()

#Printing original tree
print("\n\nOriginal Tree :\n")
root.printTree()

#Mirroring Tree
# print("\n\nStarting creation of mirror tree:\n\n")
root.mirror()

#Printing Mirrored Tree
print("\n\nMirrored Tree:\n\n")
root.printTree()

# Ending timer as program has completed requirements
end = timer()

# Printing out statistics of program
print("\n**********************\n***** Statistics *****\n**********************")
print("Number of Nodes: ",nodeCount)
print("Number of Nodes On Left Side: ",leftCounter)
print("Number of Nodes On Right Side: ",rightCounter)
print("Smallest Node Value: ",smallestValue)
print("Largest Node Value: ",largestValue)
print("Total Time of Program: {:.8f} milliseconds".format(end-start))
