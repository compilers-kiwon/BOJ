table = {"A":"a","K":"k","M":"m",\
         "O":"o","T":"t","B":"v",\
         "E":"ye","H":"n","P":"r",\
         "C":"s","Y":"u","X":"h"}

str = input()
pr = ""

for i in range(len(str)) :
    pr = pr+table[str[i]]

print(pr)