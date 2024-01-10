import sys

input = sys.stdin.readline

for i in range(0,3) :    
    N = int(input().rstrip())
    S = 0

    for j in range(0,N) :
        num = int(input().rstrip())
        S += num
    
    if S == 0 :
        print("0")
    else :
        if S > 0 :
            print("+")
        else :
            print("-")