def simulate(n) :
    ret = 0
    i = 1
    while True :
        if n < i :
            if i%2 == 1 :
                ret = i-n
            break
        n = n-i
        i = i+1
    return  ret

N = int(input())
print(simulate(N))