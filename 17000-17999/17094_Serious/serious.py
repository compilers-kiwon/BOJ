length = int(input())
s = input()

e = _2 = 0

for i in range(length) :
    if s[i] == 'e' :
        e = e+1
    else :
        _2 = _2+1

if e == _2 :
    print("yee")
else :
    if e > _2 :
        print("e")
    else :
        print("2")