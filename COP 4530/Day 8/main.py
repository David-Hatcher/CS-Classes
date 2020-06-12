#Day 8 Lecture
#
# WORD OF THE DAY: DOG
# #
# Fake Midterm
#   Test proctoring software after class
# Team Projects
#   3 Roles for each project
#       1 person for each role
#   Roles
#       Requirements Generator
#       2 Developers
#       Tester
#       Can be shifted if you don't need 2 developers#
#   Deliverables#
#       Working Code
#       A PowerPoint presentation
#       An in-class presentation
#   Grade based on Code Working and In-Class presentation#
# Stacks, Queues, Recursion
# Stacks#
# Queues#
# Recursion
# 
# Temporary Data
#   Data structures -> Performance
#   Temporary Data -> Order Matters
#       This allows you to handle data in order#
# Stacks
#   Last in, First out
#   Stores data the same as arrays
#   3 Constraints:
#       Data can only be inserted at end of stack
#       Data can only be read from eos
#       Data can only be removed from eos
#       End = top
#       Beginning = bottom
#       [] -> push 5 -> [5] -> push 3 -> [5,3] ->push 0 -> [5,3,0]
#       Cannot insert data to bottom or middle, can only be added to the top
#       Poping from stack pop 0 -> [5,3] -> pop 3 -> [5]
#       Last in, First Off
#           Like Magic
#       The Linter
#           ([{}])
#           Inspects each line of code to determine if syntax in correct
#           Syntax error Type #1:#
#              if(x>2 and (x<10):#
#           Syntax error Type #2:
#               if x>2) and (x<10):
#           SET #3:
#               if(x>2]) and (x<10):
#           You can use a stack to test this
#           Read each character
#               if character isn't a brace ignore it
#               See powerpoint for explanation
#           x = ({[1,2,3]})
#           stack = [(,{,[]
#           now we start popping when we find them
#           found ] it matches [ so pop
#           found } it matches { so pop#
#           found () it matches ) so pop
#           stack is empty, code looks good#
stack = []

def lint(text):
    for char in text:
        if char in ["(","[","{"]:
            stack.append(char)
            print("Stack: ",stack)
        elif char in [")","}","]"]:
            if len(stack) == 0:
                return "Error - unmatched", char
            lastChar = stack.pop()
            stack.append(lastChar)
            print("LastChar = ",lastChar)
            print("Character = ",char)
            if((lastChar == "(") and (char == ")")) or ((lastChar =="[") and (char == "]")) or ((lastChar == "{") and (char == "}")):
                stack.pop()
                print("Stack pop: ",stack)
            else:
                return "Error - unmatched ", char
    if len(stack) > 0:
        return("Error - opening brace without a corresponding closing brace")
    else:
        return("Success - no unmatched braces")

print(lint("x = ({[1,2,3]})"))
# Stacks in Action#
# Queues
#   First in, First out
#   3 Rules
#       Data can only be inserted at end
#       Data can only be read from front
#       Data can only be removed from front
#   FIFO = First in, First out
#   Inserting is called putting, adding, or queuing
#   [5] -> [5,9] -> [5,9,100]
#   [5,9,100] -> [9,100] -> [100]#
# Queues in Action#
queue = []

def queue_print_job(document):
    global queue
    queue.append(document)
    print(queue)

def runJob():
    global queue
    while (len(queue) > 0):
        print(queue.pop())
        printIt(queue)

def printIt(document):
    print(document)

queue_print_job("1st Doc")
queue_print_job("2nd Doc")
queue_print_job("3rd Doc")

runJob()

#
# Recursion
#   function blah(){
#       blah();
#   }
#   #
# Recursion instead of loops
def countdown(number):
    i = number
    while(i >= 0):
        print(i)
        i -= 1
countdown(10)
def countdown(number):
    print(number)
    if(number > 0):
        countdown(number-1)
countdown(10)
def countup(number):
    if(number > 0):
        countup(number-1)
    print(number)
countup(10)
#   Just because you can, doesn't mean you should
# The base case
#   A way to end the code once it's done#
# Reading recursive code
def fact(number):
    if(number == 1) or (number == 0):
        return 1
    else:
        return number * fact(number-1)
print(fact(3))
#   Start at base case, then walk UP the code to the immediately next case
#   So 1 is the base case, that returns 1
#   on 2 it returns 2 * base case = 2 * 1 = 2
#   on 3 it returns 3 * fact(2) = 6#
# Recursion in the eyes of the computer
#   Uses the call stack
#   fact(3) -> fact(2) -> fact(1)
#   Then it back tracks to the call stack
#   fact(1) is completed then fact(2) is completed then fact(3) is completed
#   In Infinite the computer keeps pushing the function onto the call stack
#       until the memory is filled and this is called a Stack Overflow#
# Recusion in action
#   #
import os

def find_directories(directory):
    os.chdir(directory)
    fileNames = os.listdir()
    for fName in fileNames:
        if(os.path.isdir(fName) and fName != "." and fName != ".."):
            print(fName)
            if(fName.find('.') == -1):
                find_directories(fName)

find_directories("..")