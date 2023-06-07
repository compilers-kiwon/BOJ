T = int(input())

for t in range(T):
    num = int(input())
    tmp = num
    print(num)

    while(tmp>=100):
        s = tmp%10
        tmp = (tmp//10)-s
        print(tmp)
    
    if( num%11 == 0 ):
        print("The number "+str(num)+" is divisible by 11.\n")
    else:
        print("The number "+str(num)+" is not divisible by 11.\n")
