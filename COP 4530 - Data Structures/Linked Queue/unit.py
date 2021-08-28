from Linked_queue import Linked_queue
import random
testPassedString = "\033[0;32m Test Passed \033[0;37m"
testFailedString = "\033[0;31m Test Failed \033[0;37m"

def randomNumber():
    return int(random.random() * 1000)
def randomCharacter():
    chars = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%&*()_+[];':<>,.?"
    return chars[randomNumber() % len(chars)]

def randomString(length):
    string = ''
    for i in range(0,length):
        string += randomCharacter()
    return string

def testResults(testTitle,recieved,expected):
    print(testTitle)
    print("Expected: ",expected,"Recieved: ",recieved)
    if(recieved == expected):
        print(testPassedString)
        return True
    else:
        print(testFailedString)
        return False

def testFront(array):
    queue = Linked_queue()
    for value in array:
        queue.push(value)
    recieved = queue.front()
    expected = array[0]
    return testResults("Front Test",recieved,expected)


def testSize(array):
    queue = Linked_queue()
    for value in array:
        queue.push(value)
    recieved = queue.getSize()
    expected = len(array)
    return testResults("Size Test: ",recieved,expected)

def testEmpty(array):
    queue = Linked_queue()
    for value in array:
        queue.push(value)
    if(len(array) != 0):
        expected = False
    else:
        expected = True
    recieved = queue.empty()
    return testResults("Empty Test",recieved,expected)

def testListSize(array,expected):
    queue = Linked_queue()
    for value in array:
        queue.push(value)
    recieved = queue.list_size()
    return testResults("List Size",recieved,expected)


#Ints [1,1000] size 5
testArray_A = [random.randint(1,1000) for _ in range(5)]

#Ints [1,1000] size 10000
testArray_B = [random.randint(1,1000) for _ in range(10000)]

#Unicode Characters range 15
testArray_C = [randomCharacter() for _ in range(15)]

#Unicode Characters range 10000
testArray_D = [randomCharacter() for _ in range(10000)]

#Unicode Strings range 15
testArray_E = [randomString(5) for _ in range(15)]

#Unicode Strings range 10000
testArray_F = [randomString(5) for _ in range(10000)]

#Empty array to be added
testArray_G = []

testFront(testArray_A)
testFront(testArray_B)
testFront(testArray_C)
testFront(testArray_D)
testFront(testArray_E)
testFront(testArray_F)
testSize(testArray_A)
testSize(testArray_B)
testSize(testArray_C)
testSize(testArray_D)
testSize(testArray_E)
testSize(testArray_F)
testSize(testArray_G)
testEmpty(testArray_F)
testEmpty(testArray_G)
testListSize(testArray_A,2)