import sys
import time as t

#Global Variables
# gValues = {}
# tSize = 0
# hashTable = {}

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

def place_word(hash,word_record,Tsize,g,increment):
    max = int(Tsize/2)
    word = word_record[0]
    OGValue = g[word[0]]
    if(increment == True):
        g[word[0]] += 1
    attempt = 0
    success = False
    while attempt <= max:
        length = word_record[2]
        g_first = g[word[0]]
        g_last = g[word[length-1]] if length != 1 else 0
        h = (length + g_first + g_last) % Tsize
        if hash[h] == '':
            hash[h] = word
            success = True
            break
        else:
            g[word[0]] += 1
            attempt += 1
    if(success == False):
        g[word[0]] = OGValue
    return success, hash



def buildHashTable(words,lettersCount):
    gValues = {}
    for key in lettersCount:
        gValues[key] = 0
    hash = {}
    for j in range(0,len(words)):
        hash[j] = ''
    i = 0
    increment = False
    while i < len(words):
        print(words[i],":::",gValues)
        if(place_word(hash,words[i],len(words),gValues,increment)[0] == False):
            increment = True
            i -= 1
        else:
            increment = False
            i += 1
    return hash






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
# print("Unique Keywords: ",keyWordSet, end = '\n\n')
lettersCount = getLetters(keyWordSet)
# print("Letters: ",lettersCount,end = '\n\n')
# populateGValues(lettersCount)
# print("G Values initial = ",gValues,end = '\n\n')
wordValues = getWordValues(keyWordSet,lettersCount)
wordValues = insertion_sort(wordValues)
print("Sorted Keywords",wordValues)
newHashTable = buildHashTable(wordValues,lettersCount)
print(newHashTable)