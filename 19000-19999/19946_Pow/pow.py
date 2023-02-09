N = int(input())

for i in range(1,65) :
    p = 1
    for j in range(1,65) :
        p = p*2
        if i==j :
            p = p-1
    if p == N :
        print(i)
        break