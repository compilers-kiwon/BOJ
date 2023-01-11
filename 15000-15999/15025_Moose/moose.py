left,right = input().split()

left=int(left)
right=int(right)

if left==0 and right==0 :
    print("Not a moose")
else :
    if left==right :
        print("Even",left+right,sep=' ')
    else :
        print("Odd",max(left,right)*2,sep=' ')