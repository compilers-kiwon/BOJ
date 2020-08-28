#include	<iostream>
#include	<vector>
#include	<stack>

using namespace	std;

#define	MAX_NUM	1299709

typedef	pair<int,int>	Range;

int	main(void)
{
	vector<bool>	prime_table(MAX_NUM+1,true);
	vector<Range>	prime_range(MAX_NUM+1);
	vector<int>		prime_number;
	
	// find primes
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( prime_table[i] == true )
		{
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				prime_table[j] = false;
			}
			prime_number.push_back(i);
		}
	}
	
	// build range
	for(int i=1;i<prime_number.size();i++)
	{
		int	from,to;
		
		from = prime_number[i-1];
		to = prime_number[i];
		
		for(int j=from+1;j<to;j++)
		{
			prime_range[j] = make_pair(from,to);
		}
	}
	
	// Do test cases
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	k;
		
		cin>>k;
		
		if( prime_table[k] == true )
		{
			puts("0");
		}
		else
		{
			cout<<prime_range[k].second-prime_range[k].first<<'\n';
		}
		
		T--;
	}
	
	return	0;
}
