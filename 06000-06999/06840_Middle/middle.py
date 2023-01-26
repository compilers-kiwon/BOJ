A = int(input())
B = int(input())
C = int(input())

sum = A+B+C
min_weight = min(A,B,C)
max_weight = max(A,B,C)

print(sum-(min_weight+max_weight))