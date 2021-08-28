
def exp(a,n):
    if(n > 0):
        return a*exp(a,n - 1)
    else:
        return 1


print(exp(3,3))