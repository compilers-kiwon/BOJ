#include	<iostream>

using namespace std;

bool	is_prime(int n)
{
	bool	result;
	int		i;
	
	for(result=true,i=2;i<=n/2;i++)
	{
		if( n%i == 0 )
		{
			result = false;
			break;
		}
	}
	return	result;
}

int		main(void)
{
	int	N,cnt,i;
	
	cin>>N;
	
	for(cnt=0,i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		
		if( n>1 && is_prime(n) == true )
		{
			++cnt;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
