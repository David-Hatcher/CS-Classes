#Lecture 14
# Graphs continued
# 
# Word of the Day: Sofa#
# 
# Homework #3
# 
# Tree Mirroring
# Graph Databases
#   Some databases store their data in the
#       for of graphs
#   Differences between graph databases and sql style
#   Using friendships in sql requires two tables
#   One for users information and second for friendship relations
#   Since rows are in order of ids, to find all one person friends
#       requires O(M log N) log N for search for M number of friends
#   If using graph, then it takes just one step per friend to find friend info
#       as each person has a pointer to their friends
# # 
# Weighted Graphs
#   This is like a regular graph but contains
#       information about the edge between the vertices
#   In example the verticies are cities and the edges are the distance
#   Shortest path problem - to find the "shorted" path from one vertex to another
# dijkstra's Algo
#   Make stating vertex current vertex
#   check all vertices adjacent tot he current vertex and calculate and record the weights from the starting vertex to all known locations
#   to determine the next current vertext, we find the cheapest unvisted known vertex that can be reached from out starting vertext
#   repeat until all vertices have been visited
#   only keep the cheapest known routes in the table
# #