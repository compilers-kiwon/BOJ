def factorial(n):
    ret = 1
    while(n>0):
        ret = ret*n
        n = n-1
    return  ret

def count_num(num,digit):
    ret = 0
    while(num>0) :
        if (num%10==digit) :
            ret = ret+1
        num = num//10
    return  ret

T = int(input())

while(T>0) :
    d,p = input().split(" ")

    d = int(d)
    p = int(p)
    
    f = factorial(d)
    n = count_num(f,p)
    
    print(n)
    T = T-1