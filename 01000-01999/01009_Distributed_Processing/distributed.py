def do_processing(a,b) :
    if b == 1 :
        ret = a%10
    elif b%2 == 0 :
        ret = do_processing(a,b/2)
        ret = (ret*ret)%10
    else :
        ret = do_processing(a,b-1)
        ret = (ret*(a%10))%10
    return  ret

T = int(input())

while T > 0 :
    a,b = input().split(' ')
    c = do_processing(int(a),int(b))

    if c == 0 :
        c = 10

    print(c)
    T -= 1