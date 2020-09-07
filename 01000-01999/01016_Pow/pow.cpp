#include	<iostream>

using namespace	std;

#define	MAX_DIFF	(1000000+1)

typedef	unsigned long long	uint64;

bool	table[MAX_DIFF];

int		main(void)
{
	uint64	min_num,max_num;
	uint64	diff,cnt;
	
	cin>>min_num>>max_num;
	diff = max_num-min_num;
	cnt = 0;
	
	for(uint64 i=2,j;(j=i*i)<=max_num;i++)
	{
		uint64	start;
		
		if( min_num%j == 0 )
		{
			start = min_num;
		}
		else
		{
			start = min_num+j-min_num%j;
		}
		
		for(uint64 k=start;k<=max_num;k=k+j)
		{
			if( table[k-min_num] == false )
			{
				table[k-min_num] = true;
				++cnt;
			}
		}
	}
	
	cout<<diff+1-cnt<<endl;
	
	return	0;
}
