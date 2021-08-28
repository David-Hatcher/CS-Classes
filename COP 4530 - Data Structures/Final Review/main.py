#Review for final
# Recursive Algorithms for Speed
# Partitioning
# Efficiency of quicksort
# Comparisons - At least N comparisons
# Swaps - randomly sorted N/4
# 1.25 N steps in quicksort or O(N)
# breaks down to N log N
#   since we break it down in halves
# Worst-Case Scenario
#   N^2
# best and average
#   N log N
# Quickselect - O(N)
# Turns out to be about 2N steps total
# Node Based Data Structures
# Linked List
#   List of items exactly like an array
#   Not colocated in memory
#   Each node stores a pointer to the next node in the list as well as the data stored in the node
#   Inserting at beginning is best case O(1)
#   Insert in middle is average case
#   Insert at end is worst case
#   Delete at beginning best case
#   Delete in middle average case
#   Delete at end worst case
# Doubly linked list
# Binary Trees
#   Hash Tables O(1) but dont retain order
#   Binary tree search log N
#   maintain order, fast insert and delete
#   two rules
#       Each node has either zero one or two children
#   if a node has two children, if must have one child with a lesser value than the parent
#   and one child with a greater value than the parent
#   Searching
#       inspect value at node, if we found it great
#       if greater than search node at left
#       if less than search node at right
#   Insertion takes O(log N)
#   Deleted node
#      the successor node is the next number up from the deleted node
#   Deleting root is the same thing READ THE SLIDES FOR THIS AS WELL
# Graphs
#   node is a vertex, line is an edge
#   if two vertices are connected by an edge they're adjacent
#   Directed graphs
#       connections are arrowed and only go in one direction
#       Twitter
#   Non-directed graph
#       connections are lines and go both ways
#       facebook
#   breadth-first search
#       goes left to right
#       keeps a queue to keep track of nodes it hasnt visited#
#   depthfirst search
#       goes top to bottom
#
#
#
#
# Rereview
# QuickSort
#   The reason we're going to dig into Quicksort even though it's built in to
#   many computer languages is because by studying how it works, we can
#   learn how to use recursion to greatly speed up an algorithm, and we can
#   do the same for other practival algorithms of the real world.
#
#   Quicksort is an extremely fast sorting alogrithm that is particularly
#   efficient for average scenarios.
#
#   While in worst-case scenarios (that is, inversely sorted arrays), it performs
#   similarly to Insertion Sort and Selection Sort, it is much faster for average
#   scenarios - which are what occur most of thetime.
#
#   Quicksort relies on a concept called partitioning
#
# Partitioning
#   To partition an array is to take a random value from the array - which is
#   then called the pivot - and make sure that every number that is less than
#   the pivot ends up to the left of the pivot, and that every number that is
#   greater than the pivot ends up to the right of the pivot
#
#   We accomplish partitioning through a simple algorithm that will be described
#   in the following example.
#
#   Lets say we have the following array: 0 5 2 1 6 3
#
#   For consistency's sake, we'll always select the right-most value to be our
#   pivot (although we can techinically choose other values).
#
#   In this case, the number 3 is our pivot.
#
#   We indicate this by circling it: 0 5 2 1 6 (3)
#
# Worst-Case Scenario
#   To put this a little more formulaically, we'd say that for N elements, there
#   are N + (N - 1) + (N - 2) + (N + -3) ... + 2 steps
#
#   This always comes out to be about (N^2)/2 steps.
#
#   Since Big O ignores constants, we'd say that in a worse-case scneario,
#   Quicksort has an efficiency of O(N^2).
#
#   Now that we've got Quicksort down, let's Compare it with Insertion Sort:
#                       Best Case           Avg Case         Worst Case
#   Insertion Sort      O(N)                O(N^2)              O(N^2)
#   Quicksort           O(N log N)          O(N log N)          O(N^2)
#
# Quickselect
#   For an array of 64 elements, we run 64 + 32 +16 +8 + 4 + 2 = 126 steps
#
#   For 128 elements, we would have 254 steps.
#
#   And for 256 elements, we would have 510 steps.
#
#   If we were to formulate this, we would say that for N elements, we would
#   have N + (N/2) + (N/4) + (N/8) + ... + 2 steps
#
#   This always turns out to be roughtly 2N steps.
#
#   Since Big O ignores constants, we would say that Quickselect has an
#   efficiency of O(N)
#
# Linked Lists
#
#   These cells are not adjacent to each other are known as nodes.
#
#   The big question is: if these nodes are not next to each other, how does
#   the computer know which nodes are part of the same linked list?
#
#   This is the key to the linked list: in addition to the data stored within the
#   node, each node also stores the memory address of the next node in the
#   linked list.
#
#   This extra piece of data - this pointer to the next node's memory
#   address - is known as the link.
#
#   Here is a visual depicition of a linked list:
#   "a" -> "b" -> "c" -> "d" -> null
#
# Reading from a linked list
#
#   We can then look up a particular index within the list with:
#       list.read(3)
#
#   If we ask a computer to look up the value at a particular index, the
#   worstcase scenario would be if we're looking up the last index in our list.
#
#   In such a case, the computer will take N steps to look up this index, since it
#   needs to start at the first node of the list and follow each link until it
#   reaches the final node.
#
#   Since Big O Notation expresses the worse-case scenario unless explicitly
#   stated otherwise, we would say that reading from a linked list has n efficiency
#   of O(N)
#
#   This is a significant disadvantage in comparison with arrays in which
#   reads are O(1)
#
# Inserting into a linked list
#   That is, inserting at the beginning is great for linked lists, but terrible for
#   arrays. And inserting at the end is an arrays' best-case scenario, but the
#   worst case when it comes to a linked list.
#
#   The following breaks this all down
#
#   Scenario                Array               Linked List
#   Insert at beg           Worst               Best
#   Insert at end           Best                Worst
#   Insert in mid           Average             Average
# Deletion
#   When it comes to deleting the final node of a linked list the actual
#   deletion takes one step - we just take the second-to-last node and make
#   it's link null
#
#   However, it takes N steps to first get to the second-to-last node, since we
#   need to start at the beginning of the list and follow the links until we reach
#   it.
#
#   The following contrasts various scenarios of deletion for both
#   arrays and linked lists. Note how it's identical to insertion:
#
#   Situation                   Array                   Linked List
#   Del at beg                  Worst                   Best
#   Del at end                  Best                    Worst
#   Del at mid                  Average                 Average
#
# Doubly Linked Lists
#   For arrays, insertion is O(1) and deletion is O(N), and for linked lists,
#   insertion is O(N) and deletion is O(1).
#
#   However, if we use a special variant of a linked list called a double linked list,
#   we'd be able to insert and delete data from a queue at O(1)
#
#   A doubly linked list is like a linked list, except that each node as two
#   links - one that points tot he next node, and one that points to the
#   preceding node.
#
#   In addition, the doubly linked list keeps track of both the first and last
#   nodes.
#
# Binary Trees
#   We've learned that has tables are O(1) for search, insertion and
#   deletion, but they have one significant disadvantage: they do not maintain
#   order.
#
#   But what do we do if we want a data structure that maintains order, and
#   also has fast search, insertion, and deletion?
#
#   Neither an ordered array nor a hash table is ideal.
#
#   Enter the binary tree.
#
#   There are many different kinds of tree-based data structures, we'll be
#   focusing on a particular tree known as a binary tree.
#
#   A binary tree is a tree that abides by the following rules:
#       Each node has either zero, one, or two children.
#
#       If a node has two children, it must have one child that has a lesser value
#       than the parent, and one child that has a greater value than the parent.
#
#   Here is an example of a binary tree, in which the values are numbers:
#                             50
#                    25               75
#                10      33        56      89
#              4   11  30  40    52  61  80  95
#
#   Because of the unique structure of a binary tree, we can search for any
#   value within it very, very quickly.
#
#   The algorithm for searching with in a binary tree begins at the root node:
#       1. Inspect the value at the node.
#       2. If we've found the value we're looking for, great!
#       3. If the value we're looking for is less than the current node, search for it
#          in its left subtree
#       4. If the value we're looking for is greater than the current node, search for it
#          in its right subtree.
#
# Insertion into Binary Tree
#
#   In this example, insertion took five steps, consisting of four search steps,
#   and one insertion step.
#
#   Insertion always takes just one extra step beyong a search, which means
#   that insertion takes log N + 1 steps, which is O(log N) as Big O ignores constants
#
#   In an ordered array, by constrast, insertion takes O(N), because in addition
#   to search, we must shift a lot of data to the right to make room for the 
#   value we're inserting.
#
#   This is what makes binary trees so efficient.
#
#   While ordered arrays have O(log N) search and O(N) insertion, binary
#   trees have O(log N) search and O(log N) insertion.
#
#   This becomes critical in an application where you anticipate a lot of change
#   to your data
#
# Deletion
#
#   When deleting a node with no children, just delete it
#
#   When deleting a node with one child, delete it and move the child to its position
#
#   When deleting a node with two children the complexity comes in (See 56 in the example)
#
#   We cannot put them both were the parent was.
#
#   That is where the next rule of the deletion algorithm comes into play:
#       WHen deleting a node with two children, replace the deleted node with
#       the successor node. The successor node is the child node whos value is the
#       Least of all values that are greater than the deleted node.
#
#   In orther words, the successor node is the next number up from the deleted value.
#
#   In this case, the next number up among the descendants of 56 is 61.
#
#   So we replace the 56 with the 61:

#
#   Now if we're deleting the root, you follow the same algorithm
#
#                             50 <- to delete
#                    25               75
#                10      33        61      89
#              4   11  30  40    52      80  95
#                                 ^ Next highest
#
#   Now that we've found the successor node - the 52 - we plug it into the node we deleted
#                             52
#                    25               75
#                10      33        61      89
#              4   11  30  40            80  95
#   And we're done
#
#   However, there is one case we haven't accounted for yet, and that's
#   where the successor node has a right child of it's own
#
#                             50
#                    25               75
#                10      33        61      89
#              4   11  30  40    52      80  95
#                                  55 <- New child
#
#   In this case we can't, simply plug the successor node - the 52 0 into the root,
#   since we'd leave it child of 55 hanging.
#
#   Because of this, there's one more rule to our deletion algorithm:
#       If the successor node has a right child, after plugging the successor into
#       the spot of the deleted node, take the right child of the successor node
#       and turn it into the left child of the parent node.#
#                             52
#                    25               75
#                10      33        61      89
#              4   11  30  40    55      80  95
#                                 ^ Moved up and left
#   And now we're really done
#
# Graphs
#
#   A graph is a data strcture that specializes in relationships, as it easily
#   conveys how data is connected
#
#   In graph jargon, each node is called a vertex, and each line is called and edge
#
#   Vertices that are connected by an edge are said to be adjacent to each other
#
#   While the facebook and twitter examples are similar, the nature of the
#   relationships ine ach example are different.
#
#   Because relationships in twitter are one-direction, we use arrows in our
#   visual implementation, and such a graph is known as a directed graph.
#
#   In Facebook, where the relationships are mutual and we use simple lines,
#   the graph is called a non-directed graph.
#
#   While a simple hash table can be used to represent a graph, a more robust
#   object oriented implementation can be used as well.
#
# Breadth-First Search(Left to right)
#
#   There are two classic ways to traverse a graph: breadth-first search and
#   depthfirst search.
#
#   We'll explore breadth-first search here, and you can look edup depth-first
#   search on your own.
#
#   Both are similar and work equally well for most cases, though.
#
#   The breadth-first search algorithm uses a queue, which keeps track of
#   which vertices to process next.
#
#   At the very beginning, the queue only contains the starting vertex (Alice, in our case).
#
#   So, when our algorithm begins, our queue looks like this:
#       [Alice]
# #