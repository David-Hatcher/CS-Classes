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
    # with the correct indentation
    def printTree(self,num = 0):
        print("    "*num,self.ID) # 4 spaces * num argument and print node ID
        if(self.left != None): # Check if left has a value
            self.left.printTree(num + 1) # Calling itself on the left node, and incrementing num
        if(self.right != None): # Check if right has a value
            self.right.printTree(num + 1) # Calling itself on the right node, ad incrementing num
    # mirror will recrusively swap all the left nodes with the right nodes and call
    # itself on the next nodes in the tree
    def mirror(self):
        global leftCounter,rightCounter,largestValue,smallestValue,nodeCount # setting global counters to increment
        self.left, self.right = self.right, self.left # Swapping left and right pointers
        nodeCount += 1 # Found a node, count it 
        print("Parent: ",self.ID) # Printing the parent, which for the left and rights is this node
        if(self.left != None): # Check if left has a pointer
            leftCounter += 1 # Found a left node, count it
            print("Left: ",self.left.ID) # Printing the left node name
        if(self.right != None): # Check if right has a pointer
            rightCounter += 1 # Found a right node, count it
            print("Right: ",self.right.ID) # Printing the right node name
        print() # putting a space afterwards
        if(self.ID > largestValue): # Checking largestValue against the current node value
            largestValue = self.ID # setting if greater
        if(self.ID < smallestValue): # Checking smallest value against the current node value
            smallestValue = self.ID # Setting if greater
        if(self.right != None): # Checking if there is a right node
            self.right.mirror() # Recursively calling itself on the right node
        if(self.left != None): # Checking if there is a left node
            self.left.mirror() # Recurisvely calling itself ont the left node


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
    print("I have set the parent for {0} to {1}".format(treeLoc.ID, treeNode.parent.ID))

    if (treeDepth < 6 and (len(nodeNames) > 0)):

        treeLoc.left  = Node(nodeNames.pop(0)) # create left child
        print("Left : ",treeLoc.left.ID)
        if (len(nodeNames) > 0):
            treeLoc.right = Node(nodeNames.pop(0)) # create right child
            print("Right: ",treeLoc.right.ID)

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

print("\nThe file that will be used for input is {0}".format(sys.argv[1]))

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

print("\nBuilding the tree:\n")
labelTree(root)

# Setting initial values for comparison of largest and smallest values in tree
largestValue = root.ID
smallestValue = root.ID

root.printTree()
root.mirror()
print("\n\n##################\nMirroring Tree\n##################\n\n")
root.printTree()

# Ending timer as program has completed requirements
end = timer()

# Printing out statistics of program
print("**********************\n***** Statistics *****\n**********************")
print("Number of Nodes: ",nodeCount)
print("Number of Nodes On Left Side: ",leftCounter)
print("Number of Nodes On Right Side: ",rightCounter)
print("Smallest Node Value: ",smallestValue)
print("Largest Node Value: ",largestValue)
print("Total time of Program: {:.8f}".format(end-start))
