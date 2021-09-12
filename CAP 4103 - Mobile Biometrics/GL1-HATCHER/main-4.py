def equation(x,y):
    numerator = (3*(x**2))*x - 16
    denominator = y - 1
    return float(numerator/denominator)

def doEquationFor(array):
    for (x,y) in array:
        print("{:.2f}".format(equation(x,y)))

def buildPairs(xStart,xEnd,yStart,yEnd):
    pairsArray = []
    for x in range(xStart, xEnd + 1):
        for y in range(yStart, yEnd + 1):
            pairsArray.append((x,y))
    return pairsArray

xOne, xTwo, yOne, yTwo = 2, 4, 5, 7
numPairs = buildPairs(xOne,xTwo,yOne,yTwo)
doEquationFor(numPairs)