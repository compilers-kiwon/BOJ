A,B,C = input().split()

A = int(A)
B = int(B)
C = int(C)

d = 1
coin = 0

while(True) :
    coin += A
    if d%7 == 0 :
        coin += B
    if coin >= C :
        break
    d += 1

print(d)