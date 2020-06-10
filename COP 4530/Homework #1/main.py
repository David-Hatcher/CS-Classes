import sys
import time as t
start = t.time()
#####################################
#         Global Variables          #
#####################################
keyWordsCount = {}
wordsCount = 0
linesCount = 0
gValues = {}
#####################################
#       Function Definitions        #
#####################################

def buildKeyWordSet(words):
    keywordArray = words.lower().split()
    keyWordSet = set(keywordArray)
    return keyWordSet

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

def getWordValues(wordSet,lettersCount):
    wordVals = []
    for word in wordSet:
        wordLength = len(word)
        letterValueFirst = lettersCount[word[0]]
        letterValueLast = lettersCount[word[-1]]
        wordValue = (word,letterValueFirst + letterValueLast,wordLength)
        wordVals.append(wordValue)
    return wordVals

def getWordValue(word):
    return word[1]

def insertion_sort(wordValues):
    for index in range(1,len(wordValues)):
        position = index
        temp_value = wordValues[index]

        while position > 0 and getWordValue(wordValues[position - 1]) < getWordValue(temp_value):
            wordValues[position] = wordValues[position -1]
            position -= 1
        wordValues[position] = temp_value
    return wordValues


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
        else:
            i += 1
    return hashTable

def checkLines(line,hashMap,gValues):
    global wordsCount
    for word in line:
        wordsCount += 1
        checkWord(word,hashMap,gValues)
    return None

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

def readFile(fileName,hashMap,gValues):
    global linesCount
    inputFile = open(fileName,'r')
    currentLine = ''
    for line in inputFile:
        linesCount += 1
        currentLine = line.lower().split()
        if len(currentLine) != 0:
            checkLines(currentLine,hashMap,gValues)

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
keyLine = keyFile.readline()
keyWordSet = buildKeyWordSet(keyLine)
lettersCount = getLetters(keyWordSet)
wordValues = getWordValues(keyWordSet,lettersCount)
wordValues = insertion_sort(wordValues)
hashTable = buildHashTable(wordValues,lettersCount)
populateKeywordCount(hashTable)
readFile(textFile,hashTable,gValues)
print('********************')
print('**** Statistics ****')
print('********************', end = '\n\n')
print('Break Down By Key Word')
print("Total Lines Read: ",linesCount)
print("Total Words Read: ",wordsCount)
totalKeywords = 0
for key in keyWordsCount:
    totalKeywords += keyWordsCount[key]
    print("{:>5} : ".format(keyWordsCount[key]),key)
print("Total Key Words: ",totalKeywords)
end = t.time()
print("Total Time of Program: {:.8f}".format(end - start))
