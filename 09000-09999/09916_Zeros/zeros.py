n = int(input())
f = 1

for i in range(1,n+1) :
    f = f*i

cnt = 0

while f > 0 :
    if (f%10)==0 :
        cnt = cnt+1
    f = f//10

print(str(cnt))