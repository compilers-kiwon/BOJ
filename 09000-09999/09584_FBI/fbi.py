def is_matched(c1,c2) :
    for i in range(len(c1)) :
        if c1[i] == '*' :
            continue
        if c1[i] != c2[i] :
            return  False
    return  True

recognized = input()
n = int(input())
matched = []

for i in range(n) :
    regist = input()
    if is_matched(recognized,regist) :
        matched.append(regist)

print(len(matched))

for i in range(len(matched)) :
    print(matched[i])