n = int(input())
arr = [0,1,1]

for i in range(3,n+1) :
    arr.append(arr[i-2]+arr[i-1])

print("{} {}".format(arr[n],n-2))