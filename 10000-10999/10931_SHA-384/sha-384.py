import hashlib

str = input()
print(hashlib.sha384(str.encode()).hexdigest())