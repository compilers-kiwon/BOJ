def change_number(num,a,b) :
    ret = 0
    for n in num :
        if int(n) == a :
            ret = ret*10+b
        else :
            ret = ret*10+int(n)
    return ret

A,B = input().split(' ')

max_sum = change_number(A,5,6)+change_number(B,5,6)
min_sum = change_number(A,6,5)+change_number(B,6,5)

print(min_sum,max_sum)