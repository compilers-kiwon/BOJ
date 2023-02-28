import hashlib

str = input()
print(hashlib.sha224(str.encode()).hexdigest())