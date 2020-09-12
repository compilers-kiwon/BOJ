#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	MAX_NUM		(1000000000+1)

typedef	unsigned long long	uint64;

int		n,len[MAX_SIZE+1];
uint64	numbers[MAX_SIZE+1],sum[MAX_SIZE+1];

void	input(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>numbers[i];
	}
}

void	find_non_decreasing_subsegments(void)
{
	numbers[0] = MAX_NUM;
	
	for(int i=1;i<=n;i++)
	{
		if( numbers[i-1] <= numbers[i] )
		{
			len[i] = len[i-1]+1;
			sum[i] = sum[i-1]+numbers[i];
		}
		else
		{
			len[i] = 1;
			sum[i] = numbers[i];
		}
	}
}

int		find_longest_subsegment(void)
{
	int		longest_len,ret;
	
	longest_len = 0;
	
	for(int i=1;i<=n;i++)
	{
		if( len[i] > longest_len )
		{
			ret = i;
			longest_len = len[i];
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_non_decreasing_subsegments();
	
	int	end_index_of_longest_non_decreasing_subsegment;
	
	end_index_of_longest_non_decreasing_subsegment = find_longest_subsegment();
	cout<<len[end_index_of_longest_non_decreasing_subsegment]<<' '<<sum[end_index_of_longest_non_decreasing_subsegment]<<'\n';
	
	return	0;
}
