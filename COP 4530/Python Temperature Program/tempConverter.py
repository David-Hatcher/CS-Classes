#CtoF returns a converts temp from Celsius to Fahrenheit
def CtoF(temp):
    return (float(temp)*9/5)+32
#FtoC returns a converts temp from Fahrenheit to Celsius
def FtoC(temp):
    return (float(temp)-32)*5/9

#get temp and what to convert to
temp = input("Enter a temperature: ")
convertTo = ''
while convertTo != 'c' and convertTo != 'f':
    convertTo = input("What would you like to convert it to?(c/f) ").lower()

#print out converted temp CtoF called if convertTo is f otherwise call FtoC
print("Converted Temp: {:.2f}".format(CtoF(temp) if convertTo == 'f' else FtoC(temp)))