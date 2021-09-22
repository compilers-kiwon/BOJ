def dfs(idx,num_list,current_sum,set_of_sum) :
    if idx == len(num_list) :
        set_of_sum.add(current_sum)
        return
    dfs(idx+1,num_list,current_sum,set_of_sum)
    dfs(idx+1,num_list,current_sum+num_list[idx],set_of_sum)

N = int(input())
num_str = input().split(' ')

M = 0
num_int = []

for n in num_str :
    M += int(n)
    num_int.append(int(n))

set_of_sum = set([])
dfs(0,num_int,0,set_of_sum)

print(M-(len(set_of_sum)-1))