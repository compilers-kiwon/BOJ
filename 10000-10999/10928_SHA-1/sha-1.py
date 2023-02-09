import hashlib

str = input()
print(hashlib.sha1(str.encode()).hexdigest())