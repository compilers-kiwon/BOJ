#include	<iostream>
#include	<map>

using namespace	std;

typedef	long long int	int64;

map<int64,int>	table;

int	main(void)
{
	int		N,max_num;
	int64	value_of_max_num;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int64	n;
		
		scanf("%lld",&n);
		table[n]++;
	}
	
	max_num = 0;
	
	map<int64,int>::iterator	it;
	
	for(it=table.begin();it!=table.end();it++)
	{
		if( it->second > max_num )
		{
			value_of_max_num = it->first;
			max_num = it->second;
		}
	}
	printf("%lld\n",value_of_max_num);
	
	return	0;
}
