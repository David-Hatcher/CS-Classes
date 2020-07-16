import sys
import time as t
#Starting timer when program is initially run
start = t.time()
#####################################
#         Global Variables          #
#####################################
#Dictionary used for determining count of each keyword
keyWordsCount = {}
#Count of total words
wordsCount = 0
#Count of total Lines
linesCount = 0
#global gValues
gValues = {}
#####################################
#       Function Definitions        #
#####################################

###
#buildKeyWordSet returns the unique list of lowercase keywords
#
def buildKeyWordSet(words):
    keywordArray = words.lower().split()
    keyWordSet = set(keywordArray)
    return keyWordSet

###
#getLetters gets the letters that begin and end each keyword\
#returns a dictionary with the letters as keys and the value as the occurances
###
def getLetters(keyWordSet):
    letters = {}
    for word in keyWordSet:
        if word[0] in letters:
            letters[word[0]] += 1
        else:
            letters[word[0]] = 1
        if word[-1] in letters:
            letters[word[-1]] += 1
        else:
            letters[word[-1]] = 1
    return letters

###
#getWordValues gets the wor value for each of the keywords based on cichelli's algo
#returns a 3-tuple with the word,the value(for sorting), and the length
###
def getWordValues(wordSet,lettersCount):
    wordVals = []
    for word in wordSet:
        wordLength = len(word)
        letterValueFirst = lettersCount[word[0]]
        letterValueLast = lettersCount[word[-1]]
        wordValue = (word,letterValueFirst + letterValueLast,wordLength)
        wordVals.append(wordValue)
    return wordVals

###
#returns the word value of the specific word given
###
def getWordValue(word):
    return word[1]

###
#insertion sort method to sort the words by value from cichelli's algo
###
def insertion_sort(wordValues):
    for index in range(1,len(wordValues)):
        position = index
        temp_value = wordValues[index]

        while position > 0 and getWordValue(wordValues[position - 1]) < getWordValue(temp_value):
            wordValues[position] = wordValues[position -1]
            position -= 1
        wordValues[position] = temp_value
    return wordValues

###
#attempts add value to the hash table, if it reaches more than 11 attempts it returns false
#and does not add the value
###
def addValue(hashTable,word_item,tSize,gValues):
    maxAttempts = int(tSize/2)
    i = 0
    word = word_item[0]
    length = word_item[2]
    success = False
    while i < tSize:
        gValueFirst = gValues[word[0]]
        if(length != 1):
            gValueLast = gValues[word[-1]]
        else:
            gValueLast = 0
        h = (length + gValueFirst + gValueLast) % tSize
        if (hashTable[h] == ''):
            hashTable[h] = word
            success = True
            break
        else:
            gValues[word[0]] += 1
            i += 1
    return success,hash

###
#build the hash table in a loop if the addvalue method returns false
#it will remove the previously added value and increment it's gValue then try to read it
#this returns a dictionary as the hashtable where the keys are the hashkey and the value is the word
##
def buildHashTable(words,lettersCount):
    global gValues
    for key in lettersCount:
        gValues[key] = 0
    hashTable = {}
    for i in range(0,len(words)):
        hashTable[i] = ''
    i = 0
    while i < len(words):
        if(addValue(hashTable,words[i],len(words),gValues)[1] == False):
            i -= 1
            h = (len(words[i]) + gValues[words[i][0][0]] + gValues[words[i][0][-1]] % len(words))
            hashTable[h] = ''
            gValues[words[i][0][0]] += 1
        else:
            i += 1
    return hashTable


###
#checkLines will check all the words in a given line to determine if they are in the keywords list
###
def checkLines(line,hashMap,gValues):
    global wordsCount
    for word in line:
        wordsCount += 1
        checkWord(word,hashMap,gValues)
    return None
###
#checkWord checks an individual word in the to determine if it is in the keywords list
###
def checkWord(word,hashMap,gValues):
    global keyWordsCount
    max = int(len(hashMap)/2)
    length = len(word)
    try:
        firstGval = gValues[word[0]]
        lastGval = gValues[word[-1]]
    except:
        return False
    for i in range(0,len(hashMap)):
        if hashMap[i] == word:
            keyWordsCount[word] += 1
            return True
    return False

###
#reads a file and checks each line to determine if the words it contains are in the keyword list
###
def readFile(fileName,hashMap,gValues):
    global linesCount
    inputFile = open(fileName,'r')
    currentLine = ''
    for line in inputFile:
        linesCount += 1
        currentLine = line.lower().split()
        if len(currentLine) != 0:
            checkLines(currentLine,hashMap,gValues)
###
#populateKeywordCount creates a dictionary to track the numbers of times
#each keyword appears in the text file that is being checked.
###
def populateKeywordCount(hashMap):
    for key in hashMap:
        keyWordsCount[hashMap[key]] = 0



if len(sys.argv) != 3:
    raise ValueError("Please provide two files names.")
sys.argv[0] = sys.argv[0][0:len(sys.argv[0]) - sys.argv[0][::-1].find('/')]

keyFile = sys.argv[0] + sys.argv[1]
textFile = sys.argv[0] + sys.argv[2]

print("The files that will be used for input are {0} and {1}".format(sys.argv[1],sys.argv[2]))

keyFile = str(sys.argv[1])
textFile = str(sys.argv[2])

keyFile = open(keyFile,'r')
#Getting keywords from file
keyLine = keyFile.readline()
#Building Unique list of keywords
keyWordSet = buildKeyWordSet(keyLine)
#counting occurance of letters
lettersCount = getLetters(keyWordSet)
#Getting word values for each word
wordValues = getWordValues(keyWordSet,lettersCount)
#Sorting words by value
wordValues = insertion_sort(wordValues)
#building out has table
hashTable = buildHashTable(wordValues,lettersCount)
#Building out dictionary of keywords to keep track of counts in
populateKeywordCount(hashTable)
#Checking second text file
readFile(textFile,hashTable,gValues)
print('********************')
print('**** Statistics ****')
print('********************', end = '\n\n')
print('Break Down By Key Word')
print("Total Lines Read: ",linesCount)
print("Total Words Read: ",wordsCount)
totalKeywords = 0
#Printing individual keyword counts
for key in keyWordsCount:
    totalKeywords += keyWordsCount[key]
    print("{:>5} : ".format(keyWordsCount[key]),key)
print("Total Key Words: ",totalKeywords)
end = t.time()
print("Total Time of Program: {:.8f}".format(end - start))
