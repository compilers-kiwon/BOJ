p = int(input())
q = int(input())

if p<=50 and q<=10 :
    state = "White"
else :
    if q>30 :
        state = "Red"
    else :
        state = "Yellow"

print(state)