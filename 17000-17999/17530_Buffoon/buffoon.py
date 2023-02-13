N = int(input())

max_score = 0
selected = False

for _ in range(0,N) :
    v = int(input())

    if v > max_score :
        if selected == False :
            max_score = v
            selected = True
        else :
            selected = False
            break

if selected == False :
    print("N")
else :
    print("S")