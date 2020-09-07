#include	<iostream>

using namespace	std;

#define	TRUE	1
#define	FALSE	0
#define	MAX_NUM	4000000

bool	not_prime_table[MAX_NUM+1];

int		found_num(int n,int D)
{
	for(;n>0;n/=10)
	{
		if( n%10 == D )
		{
			return	TRUE;
		}
	}
	
	return	FALSE;
}

void	build_not_prime_table(void)
{
	not_prime_table[1] = true;
	
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( not_prime_table[i] == false )
		{
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				not_prime_table[j] = true;
			}
		}
	}
}

int		main(void)
{
	int	A,B,D,cnt;
	
	cin>>A>>B>>D;
	
	build_not_prime_table();
	
	for(cnt=0;A<=B;A++)
	{
		if( not_prime_table[A] == false )
		{
			cnt += found_num(A,D);
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
