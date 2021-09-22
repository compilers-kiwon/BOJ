H,M = input().split(' ')
H = int(H)
M = int(M)

if H == 0 :
    H = 24

M -= 45

if M < 0 :
    M += 60
    H -= 1

print(H%24,M)