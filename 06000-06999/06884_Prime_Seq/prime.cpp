#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(10000+1)

int	n,arr[MAX_SIZE],sum[MAX_SIZE];

void	input(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum[i] = sum[i-1]+arr[i];
	}
}

bool	is_prime(int p)
{
	for(int i=2,to=sqrt(p);i<=to;i++)
	{
		if( p%i == 0 )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	find_sub_prime_seq(void)
{
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+(len-1)<=n;i++)
		{
			if( is_prime(sum[i+(len-1)]-sum[i-1]) == true )
			{
				cout<<"Shortest primed subsequence is length "<<len<<":";
				
				for(int j=0;j<len;j++)
				{
					cout<<' '<<arr[i+j];
				}
				
				cout<<'\n';
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	t;
	
	cin>>t;
	
	for(;t>0;t--)
	{
		input();
		
		if( find_sub_prime_seq() == false )
		{
			cout<<"This sequence is anti-primed.\n";
		}
	}
	
	return	0;
}
