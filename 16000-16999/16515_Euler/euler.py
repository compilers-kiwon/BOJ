f = []
f.append(1)

for x in range(1,10001) :
    f.append(f[x-1]*x)

n = int(input())
e = 0.0

n = min(170,n)

for x in range(0,n+1) :
    e = e+(1.0/float(f[x]))

print(e)