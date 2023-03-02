N = int(input())

left = 10000
right = -10000
top = -10000
bottom = 10000

for i in range(N) :
    x,y = input().split()

    x = int(x)
    y = int(y)

    left = min(left,x)
    right = max(right,x)
    top = max(top,y)
    bottom = min(bottom,y)

print(((right-left)*(top-bottom)))