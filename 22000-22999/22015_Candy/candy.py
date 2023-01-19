A,B,C = input().split()

A=int(A)
B=int(B)
C=int(C)

print(max(A,max(B,C))*3-(A+B+C))