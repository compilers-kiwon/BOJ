perfect = [100,100,200,200,300,300,400,400,500]
examinee = input().split()
score = [int(s) for s in examinee]

def is_hacker(table,score) :
    ret = False

    for i in range(len(score)) :
        if table[i] < score[i] :
            ret = True
            break
    
    return ret

if is_hacker(perfect,score) == True :
    print("hacker")
else :
    if sum(score) >= 100 :
        print("draw")
    else :
        print("none")