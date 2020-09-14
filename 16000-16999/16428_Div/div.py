s1,s2 = input().split()
a = int(s1)
b = int(s2)
if a >= 0 and b > 0:
	c = a//b
	d = a%b
elif a >= 0 and b < 0:
	c = -1*(a//abs(b))
	d = a%abs(b)
elif a < 0 and b > 0:
	d = abs(a)%b
	if d == 0:
		c = a//b
	else:
		c = -1*((abs(a)+b)//b)
		d = abs(c)*b+a
else:
	d = abs(a)%abs(b)
	if d == 0:
		c = a//b
	else:
		c = (abs(a)+abs(b))//abs(b)
		d = c*abs(b)+a
print('{}'.format(c))
print('{}'.format(d))
