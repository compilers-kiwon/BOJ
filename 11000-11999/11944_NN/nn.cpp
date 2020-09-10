#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)(c-'0'))

int	str2int(string str)
{
	int	value,i;
	
	for(value=0,i=0;i<str.length();i++)
	{
		value = value*10+char2int(str[i]);
	}
	return	value;
}

int	main(void)
{
	string	N,M;
	int		n,m,len;
	
	cin>>N>>M;
	n = str2int(N);
	m = str2int(M);
	
	len = n*N.length();
	len = min(len,m);
	
	for(int i=1,to=len/N.length();i<=to;i++)
	{
		cout<<N;
	}
	
	for(int i=0,to=len%N.length();i<to;i++)
	{
		cout<<N[i];
	}
	cout<<endl;
	
	return	0;
}
