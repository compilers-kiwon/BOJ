N = int(input())

cnt = 0
available = 30

for x in range(N) :
    T = int(input())
    time_to_study = min(available,T)

    if time_to_study*2 >= T :
        cnt = cnt+1
    
    if time_to_study >= available :
        available = 30
    else :
        available = available-time_to_study

print(cnt)