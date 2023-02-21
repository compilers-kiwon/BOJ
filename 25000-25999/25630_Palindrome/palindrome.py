N = int(input())
snack = input()

head = 0
tail = N-1
cnt = 0

while head<tail :
    if snack[head] != snack[tail] :
        cnt = cnt+1
    head = head+1
    tail = tail-1

print(cnt)