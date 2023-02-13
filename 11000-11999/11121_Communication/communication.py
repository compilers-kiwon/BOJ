T = int(input())

for _ in range(0,T) :
    in_data,out_data = input().split()

    if in_data == out_data :
        print("OK")
    else :
        print("ERROR")