# Practice for Binary Tree creation
import numpy as np

class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def __init__(self,node):
        self.root = node
    def addNum(self,node,checkNode):
        if(checkNode == None):
            checkNode = node
        elif(checkNode.data < node.data):
            if(checkNode.right == None):
                checkNode.right = node
            else:
                self.addNum(node,checkNode.right)
        elif(checkNode.data > node.data):
            if(checkNode.left == None):
                checkNode.left = node
            else:
                self.addNum(node,checkNode.left)
        elif(checkNode.data == node.data):
            print("Value {} in tree".format(node.data))
            pass
    def insert(self,node):
            self.addNum(node,self.root)
    def printTree(self,node = None):
        print()
        if(node == None):
            node = self.root
        print("Parent: {}".format(node.data))
        if(node.left != None):
            print("Left: {}".format(node.left.data))
        if(node.right != None):
            print("Right: {}".format(node.right.data))
        if(node.left != None):
            self.printTree(node.left)
        if(node.right != None):
            self.printTree(node.right)

def verif(node,array = [float('-inf'),float('inf')]):
    isTreeValid = True
    if(node.right != None and node.right.data > array[1]):
        return False
    if(node.left != None and node.left.data < array[0]):
        return False
    elif(node.left != None):
        isTreeValid = verif(node.left,[array[0], node.data if node.data < array[1] else array[1]])
    elif(node.right != None):
        isTreeValid = verif(node.right,[node.data if node.data > array[0] else array[0], array[1]])
    return isTreeValid

def checkDepth(node,currentDepth = 0,array = []):
    if(node.left == None and node.right == None):
        array.append(currentDepth)
    else:
        currentDepth += 1
        if(node.left != None):
            checkDepth(node.left,currentDepth,array)
        if(node.right != None):
            checkDepth(node.right,currentDepth,array)
    return np.max(array)


nodeA = Node(5)
# nodeB = Node(2)
# nodeC = Node(3)
# nodeD = Node(7)
# nodeE = Node(9)
# nodeF = Node(4)
# nodeG = Node(18)

# nodeF.right = nodeG
# nodeD.right = nodeE
# nodeB.right = nodeC
# nodeC.right = nodeF
# nodeA.right = nodeD
# nodeA.left = nodeB
print(verif(nodeA))

tree = Tree(nodeA)
tree.insert(Node(2))
tree.insert(Node(3))
tree.insert(Node(7))
tree.insert(Node(9))
tree.insert(Node(4))
tree.insert(Node(18))
tree.insert(Node(22))
tree.insert(Node(35))
tree.insert(Node(10))
tree.insert(Node(15))
tree.printTree()
print("Depth of tree: ",checkDepth(nodeA))