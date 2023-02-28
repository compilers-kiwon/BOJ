def count_steps():
    ret = 0
    steps = input()

    while ret < len(steps) :
        if steps[ret] == 'D' :
            break
        ret = ret+1
        
    return  ret

T = int(input())

for i in range(T) :
    print(count_steps())