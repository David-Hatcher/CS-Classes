import time as t
# start = t.time()
#GLOBAL DEFINITIONS
gValueInitial = 11
gValues = {}
cTable = {}
lineCount = 0
wordsCount = 0
keyWordsCount = 0
KEY_FILE_NAME = "HW1-MLKSpeechP1.txt"
TEXT_FILE_NAME = "HW#1-MLKSpeech.txt"

#Build Inital gvalues
def buildGValues():
    global gValues
    alpha = 'a'
    for i in range(0,26):
        gValues[alpha] = 11
        alpha = chr(ord(alpha) + 1)

def h(word,size):
    return ((len(word) + gValues[word[0]] + gValues[word[-1]]) % size)

#Build the first and last letter values dictionary
def buildFLDict(words):
    firstLastDict = {}
    for word in words:
        if(word[0] in firstLastDict):
            firstLastDict[word[0]] += 1
        else:
            firstLastDict[word[0]] = 1
        if(word[-1] in firstLastDict):
            firstLastDict[word[-1]] += 1
        else:
            firstLastDict[word[-1]] = 1
    return firstLastDict

#Get values for each word
def getWordValues(words,firstLastValues):
    wordDict = {}
    for word in words:
        wordDict[word] = firstLastValues[word[0]] + firstLastValues[word[-1]]
    return wordDict

#return the words as an ordered list based on the Cichelli Value
def OrderWords(words):
    orderedWords = []
    wordTupes = list(words.items())
    for index in range(1,len(wordTupes)):
        position = index
        temp_value = wordTupes[index]
        while position > 0 and wordTupes[position - 1][1] > temp_value[1]:
            wordTupes[position] = wordTupes[position -1]
            position -= 1
        wordTupes[position] = temp_value
    for words in wordTupes:
        orderedWords.append(words[0])
    return orderedWords

def updateGValue(word):
    global gValues
    gValues[word[0]] += 1


#Cichelli's Table Build
def buildCTable(words):
    cTable = {}
    for word in words:
        index = h(word,len(words))
        while index in cTable:
            index = h(word,len(words))
            updateGValue(word)
        cTable[index] = word
    return cTable

#Read from keyword file to grab keywords and return set of unique keywords
def getKeywords(fileName):
    keyFile = open(fileName,"r")
    firstLine = keyFile.readline()
    newLineStrip = firstLine.strip('\n').lower()
    keyWords = set(newLineStrip.split(' '))
    keyWords = filter(bool,keyWords)
    keyFile.close()
    return set(keyWords)


def getWords(fileName):
    global wordsCount
    words = list()
    textFile = open(fileName,"r")
    newLine = textFile.readline()
    wordsCount += 1
    while newLine:
        newLineStrip = newLine.strip('\n').lower().split(' ')
        newLineStrip = filter(bool,newLineStrip)
        words.extend(list(newLineStrip))
        newLine = textFile.readline()
        wordsCount += 1
    textFile.close()
    return words

def createHashMap(fileName):
    buildGValues()
    keyWords = getKeywords(fileName)
    firstLastDict = buildFLDict(keyWords)
    wordValuesDict = getWordValues(keyWords,firstLastDict)
    orderedWords = OrderWords(wordValuesDict)
    cTable = buildCTable(orderedWords)
    return cTable

def checkWords(words,hashMap):
    global keyWordsCount
    for word in words:
        print(word)
        hval = h(word,len(hashMap))
        if (hval in hashMap) and (hashMap[hval] == word):
            keyWordsCount += 1


#Code for program
start = t.time()
hashMap = createHashMap(KEY_FILE_NAME)
words = getWords(TEXT_FILE_NAME)
# print(words)
# checkWords(words,hashMap)
print(hashMap)
end = t.time()
# print("Words Count: ",wordsCount)
# print("Keywords Count: ",keyWordsCount)
# print("Time: {:.8f}".format(end - start))