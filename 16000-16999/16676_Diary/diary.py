N = int(input())

current_num = 10
num_of_packs = 1

while current_num < N :
    num_of_packs = num_of_packs+1
    current_num = current_num*10+10

print(num_of_packs)