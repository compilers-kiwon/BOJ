a,b,c = input().split()

a = int(a)
b = int(b)
c = int(c)

if a+b+c == 2*max(a,b,c) :
    print(1)
elif a*b*c == max(a,b,c)**2 :
    print(2)
else :
    print(3)