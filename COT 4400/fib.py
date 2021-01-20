import time
fibArr = []
fibNum = 33

def fibRec(n):
    if n <= 1:
        return n
    else:
        return fibRec(n-1) + fibRec(n-2)

def fib(n):
    global fibArr
    fibArr = [-1] * n
    #return DynamicFib(n)
    return iterativeFib(n)

def DynamicFib(n):
    if(fibArr[n-1] == -1):
        if n <= 2:
            fibArr[n-1] = 1
        else:
            fibArr[n-1] = DynamicFib(n-1) + DynamicFib(n-2)
    return fibArr[n-1]

def iterativeFib(n):
    global fibArr
    for i in range(1,n + 1):
        if(i == 1 or i == 2):
            fibArr[i] = 1
        else:
            fibArr[i] = fibArr[i-1] + fibArr[i-2]
    return fibArr[n]

print("Enter a number to find the Fibonacci value of that number:")
fibNum = int(input())

start = time.time()
fibVal = fibRec(fibNum)
end = time.time()
print(fibVal)
totalTimeRec = end - start
print("Total Time for Recursive = {:2.5f}".format(totalTimeRec), " seconds")

start = time.time()
fibVal = fib(fibNum)
end = time.time()
print(fibVal)
totalTimeDyn = end - start + 0.00001 #Adding tiny value to avoid divide by 0 error
print("Total Time for Dynamic Programming = {:2.5f}".format(totalTimeDyn), " seconds")

print("Dynamic Programming is",totalTimeRec/totalTimeDyn, "times faster than recursive")