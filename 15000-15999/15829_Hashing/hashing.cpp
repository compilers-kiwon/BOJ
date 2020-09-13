#include	<iostream>
#include	<string>

using namespace	std;

#define	MOD(n)		((n)%1234567891)
#define	char2int(c)	((int)((c)-'a')+1)

typedef	unsigned long long	uint64;

uint64	pow(int n,int i)
{
	uint64	result;
	int		j;
	
	for(result=1,j=1;j<=i;j++)
	{
		result = MOD(result*(uint64)n);
	}
	
	return	result;
}

int		main(void)
{
	int		L,i,r;
	uint64	H;
	string	str;
	
	cin>>L>>str;
	
	for(H=i=0,r=31;i<str.length();i++)
	{
		H += MOD((uint64)(char2int(str[i]))*pow(r,i));
		H = MOD(H);
	}
	
	cout<<H<<endl;
	
	return	0;
}
