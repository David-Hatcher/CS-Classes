from timeit import default_timer as timer

#
# Examples of reading, search, adding and deleting from an array
#

array = ["apples", "bananas", "cucumbers", "dates", "elderberries"]

def readArray():
    print("Reading from array")
    print(array)
    start = timer()
    print(array[1])
    end = timer()
    print("Read elapsed time = {0:.8f}".format(end - start))



def searchArray():
    print("Searching array for dates")
    print(array)
    start = timer()
    index = 0
    fruit = ""
    while (fruit != "dates"):
        fruit = array[index]
        index += 1
    print(array[index -1]," was found at index",index-1)
    end = timer()
    print("Search elapsed time = {0:.8f}".format(end - start))



def insertArray():
    print("Inserting figs into array")
    print(array)
    start = timer()
    #code to replace
    #array.insert(2,"figs")
    end_index = len(array) - 1
    array.append("") #add empty string to end of array
    while end_index != 1:
        array[end_index + 1] = array[end_index] #shift current value to next value
        end_index -= 1 #decrement
    array[2] = "figs" #insert figs into second position
    print(array)
    end = timer()
    print("Insert elapsed time = {0:.8f}".format(end - start))


def deleteArray():
    print("Deleting bananas from array")
    print(array)
    start = timer()
    #Code to replace
    #array.pop(1)
    array[1] = "" #overwrite selected value
    index = 1 #start at index of deleted value
    while index != len(array) - 1:  #Continue while index is still inside bounds
        #current value becomes next value
        array[index] = array[index + 1] #shift next value to current value
        index += 1 #increment
    array[index] = ""
    print(array)
    end = timer()
    print("Delete elapsed time = {0:.8f}".format(end - start))

selection = -1
while (selection != 5):
    print()
    print("1. Read from array")
    print("2. Search array")
    print("3. Insert into array")
    print("4. Delete from array")
    print("5. Quit")
    selection = int(input("Enter array action desired: "))
    print()

    if (selection == 1):   readArray()
    elif (selection == 2): searchArray()
    elif (selection == 3): insertArray()
    elif (selection == 4): deleteArray()
    else:
        print("All Done")
        break
