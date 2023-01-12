X,L,R = input().split()

X = int(X)
L = int(L)
R = int(R)

min_diff = 100000

for i in range(L,R+1) :
    if abs(X-i) < min_diff :
        min_diff = abs(X-i)
        min_diff_num = i

print(min_diff_num)