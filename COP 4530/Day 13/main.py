#Lecture notes Day 14
# Graphs, Breadth-first search
# People can be "Friends"
# #
relationships = [
    ["Alice","Bob"],
    ["Bob","Cynthia"],
    ["Alice", "Diana"],
    ["Bob","Diana"],
    ["Elise","Fred"],
    ["Diana","Fred"],
    ["Fred","Alice"]
]
#This is a bad way of structuring the data
#This is O(N)
#Nodes are called vertex, lines are called edge
#verticies connected by an edge are adjacent to each otuer
friends = {
    "Alice":["Bob","Diana","Fred"],
    "Bob":["Alice","Cynthia","Diana"],
    "Cynthia":["Bob"],
    "Diana":["Alice","Bob","Fred"],
    "Elise":["Fred"],
    "Fred":["Alice","Diana","Elise"]
}

#twitter is different, follows aren't always mutual
followees = {
    "Alice":["Bob","Cynthia"],
    "Bob":["Cynthia"],
    "Cynthia":["Bob"]
}
#if the graph has arrows, it's directed graph
#with just lines it's a non directed graph
class Person:
    def __init__(self,name):
        self.name = name
        self.friends = []
        self.visited = False
    def addFriend(self,friend):
        self.friends.append(friend)
    def display_network(self):
        queue = []
        queue.append(self)

        to_reset = []
        to_reset.append(self)
        while len(queue) > 0:
            current_vertex = queue.pop(0)
            print(current_vertex.name)
            for friend in current_vertex.friends:
                if friend.visited == False:
                    friend.visted = True
                    queue.append(friend)
                    to_reset.append(friend)
        for item in to_reset:
            item.visited = False

    
mary = Person("Mary")
peter = Person("Peter")

mary.addFriend(peter)
peter.addFriend(mary)

print(mary.friends[0].name)
print(peter.friends[0].name)

#Linked in
#Alice - Bob - Cynthia
#Bredth-First
    #Make alice the first vertex
    #First visit bob, bob added to queue
    #queue has just bob
    #now check for adjacent verticies
    #found candy, add candy to queue
    #same thing for derek and elaine
    #Queue is bob,candy,derek,elaine
    #How we remove bob and make it our current vertex
    #queue is candy, derek, elain. Bob is a current vertex
    #now find any unvisited vertices of the current vertex
    #find fred and add to queue
    #queue is now candy, derek, elain, fred
    #remove candy and make current vertex, no unvisted verticies
    #now grab derek as current vertex
    #queue is elain, fred
    #add gina to queue from derek's connections
    #queue is elain, fred, gina
    #so on so forth
    #O(V) V Verticies added to the queue and V verticies removed
    #O(V+E)
#Depth-First
