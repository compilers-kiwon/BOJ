A,B = input().split(' ')
C = int(A)-int(B)

if C > 0 :
    print('>')
elif C < 0 :
    print('<')
else :
    print('==')