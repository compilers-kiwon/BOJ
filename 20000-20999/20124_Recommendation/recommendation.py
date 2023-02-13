N = int(input())

name = ""
score = 0

while N > 0 :
    A,B = input().split()
    
    if score<int(B) or (score==int(B) and A<name ) :
        score = int(B)
        name = A

    N = N-1

print(name)