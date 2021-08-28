#Lecture 12
#
#Word of the Day Envelope
# Linked Lists
#   Implementing a linked List
#   Reading
#   Searching
# Node based data structures
#   Provide a number of preformance advantages
#   The Linked List
#   Similar to array, but has a special set of trade offs
# Linked List
#   Data structure that rep a list of items, almost like array
# Node
#   An object that stores a pointer, or object, to the next
#       object in the linked list
# Arrays can jump straight to a specific index
# Linked lists cannot do this as they must go to each node
#   to find the next one
# Nodes are not stored next to each other
# One advantage over an array is that the program doesnt
#   need to find adjacent memory slots#
class Node:
    def __init__(self,data,next = None):
        self.data = data
        self.next = next
    def next_node(self,next = None):
        self.next = next


node_A = Node("1")
node_B = Node("2")
node_C = Node("3")
node_B.next_node(node_C)
node_A.next_node(node_B)

print(node_A.data)
print(node_A.next.data)

class Linked_List:
    def __init__(self,head):
        self.head = head
    def read(self,index):
        counter = 0
        node = self.head
        while counter <= index:
            if(counter == index):
                return node.data
            elif(node.next == None):
                return None
            else:
                counter += 1
                node = node.next
    def append(self,node):
        curNode = self.head
        while(curNode.next != None):
           curNode = curNode.next
        curNode.next_node(node)
    def delete(self,index):
        curNode = self.head
        counter = 1
        if(index == 0):
            self.head = self.head.next
            return True
        else:
            curNode = curNode.next
        while(curNode.next != None):
            if(counter == index):
                curNode.next = curNode.next.next
                return True
        return False
lList = Linked_List(node_A)

print(lList.read(2))

newList = Linked_List(Node(1))
newList.append(Node(2))
newList.append(Node(3))

print(newList.read(0))

print(newList.delete(0))
print(newList.read(0))

#Insertion
#   Insert beginning Array worst case = O(N)
#   Insert Array beginning worst case with Linked List = O(1)
#       This is done by creating a new node and just adding it to the
#           head of the list
#   Scenario        Array       LL
#   Insert beg      Worst       Best
#   Middle          Average     Average
#   End             Best        Worst
#   Total insert worst case for LL O(N)
#   If only adding at beginning, LL is great
# Delete
#   Popping from start, just change head to head.next value
# 
# 
# If we're doing a lot at the beginning of a set of data
#   a LL is a good way to go
# If we're doing a lot at the end, an array is a good way to go
# 
# Doubly Linked Lists
#   Same as a linked list but you have a next and prev
# #

class DLNode:
    def __init__(self,data,next = None,prev = None):
        self.next = next
        self.prev = prev
        self.data = data

# Go watch last few minutes of lecture for what is happening thursday.#