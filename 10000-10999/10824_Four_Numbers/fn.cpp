#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

uint64	str2uint64(string& str)
{
	uint64	value = 0;
	
	for(int i=0;i<str.length();i++)
	{
		value = value*10+(uint64)(str[i]-'0');
	}
	return	value;
}

int		main(void)
{
	string	A,B,C,D,AB,CD;
	
	cin>>A>>B>>C>>D;
	
	AB.append(A);AB.append(B);
	CD.append(C);CD.append(D);
	 
	uint64	ab = str2uint64(AB);
	uint64	cd = str2uint64(CD);
	
	cout<<ab+cd<<endl;
	
	return	0;
}
