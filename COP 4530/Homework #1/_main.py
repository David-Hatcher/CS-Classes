import time as t
keywordCount = 0
start = t.time()
counter = 0
keyInput = open("HW1-MLKSpeechP1.txt",'r')
keywords = set(keyInput.readline().lower().split())
wordsInput = open("HW#1-MLKSpeech.txt",'r')
text_to_read = []
for line in wordsInput:
    text_to_read.extend(line.lower().split())
for word in keywords:
    for j in range(0,len(text_to_read)):
        counter += 1
        if(word == text_to_read[j]):
            keywordCount += 1
end = t.time()
print(keywordCount)
print(counter)
print("{:.8f}".format(end-start))