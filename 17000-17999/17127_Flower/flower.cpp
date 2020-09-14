#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10+1)

int	get_mul(int from,int to,int* data)
{
	int	ret;
	
	for(ret=1;from<=to;from++)
	{
		ret *= data[from];
	}
	
	return	ret;
}

int	get_value(int e1,int e2,int e3,int e4,int* data)
{
	int	ret;
	
	ret = get_mul(1,e1,data)+get_mul(e1+1,e2,data)+get_mul(e2+1,e3,data)+get_mul(e3+1,e4,data);
	
	return	ret;
}

int	main(void)
{
	int	N,tree[MAX_SIZE],max_value;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>tree[i];
	}
	
	max_value = 0;
	
	for(int g1_end=1;g1_end<=N-3;g1_end++)
	{
		for(int g2_end=g1_end+1;g2_end<=N-2;g2_end++)
		{
			for(int g3_end=g2_end+1;g3_end<=N-1;g3_end++)
			{
				max_value = max(max_value,get_value(g1_end,g2_end,g3_end,N,tree));
			}
		}
	}
	
	cout<<max_value<<'\n';
	
	return	0;
}
