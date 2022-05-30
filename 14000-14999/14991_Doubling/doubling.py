n = int(input())
b = [int(x) for x in input().split(" ")]

v = 1
i = 0

while(i<n) :
    v = v*2
    
    if( v < b[i] ) :
        break

    v = v-b[i]
    i = i+1
    
if( i == n ) :
    print(v%1000000007)
else :
    print("error")