# Python3 code to demonstrate  
# Filling alphabets 
# using naive method  
  
# initializing empty list  
dict = {}
  
# printing initial list  
print ("Initial list : " + str(dict)) 
  
# using naive method 
# for filling alphabets 
alpha = 'a'
for i in range(0, 26): 
    dict[alpha] = 11
    alpha = chr(ord(alpha) + 1)  
  
# printing resultant list  
print ("List after insertion : " + str(dict)) 