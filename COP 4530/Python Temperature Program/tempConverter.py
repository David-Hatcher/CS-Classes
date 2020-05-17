#CtoF returns a converts temp from Celsius to Fahrenheit
def CtoF(temp):
    return (int(temp)*9/5)+32
#FtoC returns a converts temp from Fahrenheit to Celsius
def FtoC(temp):
    return (int(temp)-32)*5/9
#getTemp ask the users to enter a temp and returns their input
def getTemp():
    print("Enter a Temp: ",end = '')
    return input()
#getMeasurement asks the user what measurement their temperature is in and returns their input
def getMeasurement():
    print("Is this Celsius or Fahrenheit? (C for Celsius, F for Fahrenheit): ", end = '')
    return input()
#askContinue asks the user if they'd like to continue and returns their input
def askContinue():
    print("Would you like to convert another temperature?(y/n): ", end = '')
    return input()

#cont is the variable that is used to determine if they'd like to continue
cont = 'y'

while cont.lower() != 'n':
    #users input temp
    temp = (getTemp())
    #users scale value
    measurement = getMeasurement()
    while(measurement.lower() != 'c' and measurement.lower() != 'f'):
        #if input is incorrect
        print("Incorrect value, please enter C or F")
        measurement = getMeasurement()
    if measurement == 'C' or measurement == 'c':
        print("{:3.2f} degrees Fahrenheit".format(CtoF(temp)))
    else:
        print("{:3.2f} degrees Celsius".format(FtoC(temp)))
    #would they like to continue
    cont = askContinue()
#stops console from closing
input()