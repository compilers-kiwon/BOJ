#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

string	A,B;
uint64	A_cnt[10],B_cnt[10];

void	input(void)
{
	cin>>A>>B;
	
	for(int i=0;i<A.length();i++)
	{
		A_cnt[(int)(A[i]-'0')]++;
	}
	
	for(int i=0;i<B.length();i++)
	{
		B_cnt[(int)(B[i]-'0')]++;
	}
}

uint64	multiply(void)
{
	uint64	ret;
	
	ret = 0;
	
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			ret += A_cnt[i]*B_cnt[j]*(uint64)(i*j);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<multiply()<<'\n';
	
	return	0;
}
