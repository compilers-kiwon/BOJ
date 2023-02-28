n = int(input())
date = ""

for i in range(n//5) :
    date = date+'V'

for i in range(n%5) :
    date = date+'I'
    
print(date)