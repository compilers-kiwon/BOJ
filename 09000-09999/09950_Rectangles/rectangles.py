while True :
    a,b,c = input().split()

    a = int(a)
    b = int(b)
    c = int(c)

    if a+b+c == 0 :
        break;

    if a == 0 :
        a = c//b
    if b == 0 :
        b = c//a
    if c == 0 :
        c = a*b
    
    print(str(a)+" "+str(b)+" "+str(c))