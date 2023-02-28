import hashlib

str = input()
print(hashlib.md5(str.encode()).hexdigest())