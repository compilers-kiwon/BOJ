#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000000

void	build_prime_table(vector<bool>& is_prime)
{
	is_prime.resize(MAX_SIZE+1,true);
	is_prime[1] = false;
	
	for(int i=2;i<=MAX_SIZE;i++)
	{
		if( is_prime[i] == true )
		{
			for(int j=i+i;j<=MAX_SIZE;j+=i)
			{
				is_prime[j] = false;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<bool>	is_prime;
	
	build_prime_table(is_prime);
	
	for(;;)
	{
		int	a,d,n,cnt;
		
		cin>>a>>d>>n;
		
		if( a==0 && d==0 && n==0 )
		{
			break;
		}
		
		if( is_prime[a] == true )
		{
			cnt = 1;
		}
		else
		{
			cnt = 0;
		}
		
		for(;cnt!=n;)
		{
			a += d;
			
			if( is_prime[a] == true )
			{
				cnt++;
			}
		}
		
		cout<<a<<'\n';
	}
	
	return	0;
}
