import hashlib

str = input()
print(hashlib.sha512(str.encode()).hexdigest())