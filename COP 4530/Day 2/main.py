#Day 2 Lecture Notes
# 

#  WORD OF THE DAY: Trapdoor
# Lists
#
prerequisites = ['COP4530','Data Structures',3]
#Python doesn't care what type a variable is
example1 = 'a'  #char
example1 = 5    #int
example1 = 7.3  #float
myList = ['a',5,7.3]
print(myList)
print(len(myList))
multiList = [[1,2,3],[4,5,6],[7,8,9]]
print(multiList)
print(multiList[-1])

#Strings are immutable, cannot change values
name = "Pat"
#name[0] = "M"
#Lists can be changed
multiList[0] = [0,1,2]
print(multiList)

#append
prerequisites.append("Dr. Anderson")
prerequisites.append(2020)
print(prerequisites)

#appending elements
goodFood = []
goodFood.append("burgers")
goodFood.append("Hot Dog")

#Pop
prerequisites.pop() #removes last element
prerequisites.pop(2) # removes element at index of 2

#Remove
prerequisites.remove("Dr. Anderson") #removes first one is finds

#insert
prerequisites.insert(2,"Really Hard")#adds to index 2

#extendputs a list on the end of a list
prerequisites.extend(["Dr. Anderson",2020]) #adds to the end of the list

print(prerequisites)

if "Dr. Anderson" in prerequisites:
    print("Dr. Anderson in prereqs at",prerequisites.index("Dr. Anderson",0,len(prerequisites)-1)) #star and stop not required

values = [1,2,3,4,1,5,23,32,4,3,2,5]

while 1 in values:
    values.remove(1)
print(values)

montInQuarter = [1,2,3] * 4
print(montInQuarter)

monthlyScores = [0] * 12

print([1,4,9] == [1,4,9])
print([1,4,9] == [4,1,9])

scores = [10,9,7,6,5]
values = scores #copy by reference
scores[3] = 10
print(values,scores) #same values still
scores = list(values) #copy by values
scores[3] = 22
print(values,scores) #different numbers

#Tables(Matrices) list of lists
counts = [
    [1,0,1],
    [1,1,0],
    [0,0,1],
    [1,0,0],
    [0,1,1]
]

medalCount = counts[3][1]

# Sets
#collection of unique values
cheesePizza = {"Parmesan Sauce","Cheese","Toasted Parmesan"}
print(cheesePizza)
cheesePie = ["Parmesan sauce", "Cheese", "Toasted Parmesan"]
print(cheesePizza)
cheesePizza = set(cheesePie)

if "Toasted Parmesan" in cheesePizza:
    print("Toasted Parm in cheesePizza")
else:
    print("Toasted Parm not in cheesePizza")

#add

cheesePizza.add("Mushrooms")
cheesePizza.add("Mushrooms")#ignored
print(cheesePizza)


#discard

cheesePizza.discard("Mushroom") #trys and if fails, does nothing

#remove
#cheesePizza.remove("Mushroom") #throws exception if fails

#clear
cheesePizza.clear() #clears entire set
print(cheesePizza)

# Dictionaries

# Functions
#send arguments, recieve parameters

def selectFlavor(yogurt):#parameters
    flavors = ['chocolate','vanilla','strawberry']
    if yogurt in flavors:
        return "Flavor in stock"
    else:
        return "Flavor not in stock"

print(selectFlavor("chocolate"))#arguments
print(selectFlavor("mint"))

# Global Variables#
balance = 10000
def withdraw(amount):
    global balance #defining it as global so it can be adjusted
    if balance >= amount:
        balance -= amount

withdraw(500)
print(balance)


#classes

class car():
    def __init__(self,model,color): #Self is always the first parameter of all methods
        self.model = model
        self.color = color
    def show(self):
        print("Model is",self.model)
        print("Color is",self.color)


audi = car("Audi A4","Blue")
ferrari = car("Ferrari 488","Green")

audi.show()
ferrari.show()

class Shark:
    animal_type = "Fish" #class variable, static
    def __init__(self,name,age):
        self.name = name #instance variables
        self.age = age #instance variables
        myAge  = age #local variable
