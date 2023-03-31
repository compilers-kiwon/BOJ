def remove_sub_str(str,lower,upper) :
    ret = ""
    for i in range(len(str)) :
        if i<lower or i>=upper :
            ret = ret+str[i]
    return  ret

n = int(input())

for i in range(n) :
    s,i,j = input().split()
    print(remove_sub_str(s,int(i),int(j)))