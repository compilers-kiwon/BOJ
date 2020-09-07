#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_NUM	1000000000

void	init_sum_table(vector<int>& sum)
{
	uint64	s,i;
	
	for(s=1,i=2;s<=MAX_NUM;i++)
	{
		sum.push_back((int)s);
		s = s+i;
	}
}

int		binary_search(int& n,vector<int>& table)
{
	int	lo,mid,hi;
	
	lo = 0;
	hi = table.size();
	
	while(lo+1<hi)
	{
		mid = (lo+hi)/2;
		
		if( table[mid] < n )
		{
			lo = mid;
		}
		else if( table[mid] > n )
		{
			hi = mid;
		}
		else
		{
			lo = mid;
			break;
		}
	}
	n -= table[lo];
	return	lo+1;
}

int		main(void)
{
	vector<int>	sum_table;
	int			cnt,n;
	
	init_sum_table(sum_table);
	
	cin>>n;
	cnt = 0;
	
	while( n>0 )
	{
		cnt += binary_search(n,sum_table);
	}
	cout<<cnt<<endl;
	
	return	0;
}
