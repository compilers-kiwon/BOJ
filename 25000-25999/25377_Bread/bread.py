N = int(input())
earliest_time_to_get_bread = 1000+1

for i in range(N) :
    A,B = input().split()
    A = int(A)
    B = int(B)

    if A > B : continue
    if B < earliest_time_to_get_bread :
        earliest_time_to_get_bread = B

if earliest_time_to_get_bread == 1000+1 :
    earliest_time_to_get_bread = -1

print(earliest_time_to_get_bread)