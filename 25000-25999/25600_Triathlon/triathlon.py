def get_score():
    a,d,g = input().split()
    
    a = int(a)
    d = int(d)
    g = int(g)
    
    ret = a*(d+g)

    if a == (d+g) :
        ret = ret*2
    
    return  ret

N = int(input())
max_score = 0

for i in range(0,N) :
    max_score = max(max_score,get_score())

print(max_score)