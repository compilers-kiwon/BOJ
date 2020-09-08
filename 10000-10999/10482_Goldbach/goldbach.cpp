#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	32000

vector<bool>	is_prime(MAX_NUM+1,true);
vector<int>		primes;

typedef	pair<int,int>	Sum;

void	find_prime(void)
{
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( is_prime[i] == true )
		{
			primes.push_back(i);
			
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				is_prime[j] = false;
			}
		}
	}
}

void	find_sum(vector<Sum>& solutions,int n)
{
	for(int i=0;i<primes.size()&&primes[i]<=n/2;i++)
	{
		if( is_prime[n-primes[i]] == true )
		{
			solutions.push_back(make_pair(primes[i],n-primes[i]));
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	find_prime();
	
	int	n,x;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		
		vector<Sum>	s;
		
		find_sum(s,x);
		
		cout<<x<<" has "<<s.size()<<" representation(s)\n";
		
		for(int j=0;j<s.size();j++)
		{
			cout<<s[j].first<<'+'<<s[j].second<<'\n';
		}
		
		cout<<'\n';
	}
	
	return	0;
}
