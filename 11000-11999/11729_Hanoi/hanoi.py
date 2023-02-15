move = []

def hanoi(n,src,temp,dst) :
    if n == 1 :
        move.append([src,dst])
    else :
        hanoi(n-1,src,dst,temp)
        move.append([src,dst])
        hanoi(n-1,temp,src,dst)

N = int(input())
hanoi(N,1,2,3)

print(len(move))

for x in move :
   print(str(x[0])+" "+str(x[1]))