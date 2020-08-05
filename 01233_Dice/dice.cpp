#include	<iostream>

using namespace	std;

#define	MAX_SUM	80

int	main(void)
{
	int	sum[MAX_SUM+1];
	int	S1,S2,S3,max_sum,to,max_sum_index;
	
	cin>>S1>>S2>>S3;
	to = S1+S2+S3;
	
	for(int i=3;i<=to;i++)
	{
		sum[i] = 0;
	}
	
	for(int i=1;i<=S1;i++)
	{
		for(int j=1;j<=S2;j++)
		{
			for(int k=1;k<=S3;k++)
			{
				sum[i+j+k]++;
			}
		}
	}
	
	max_sum = 0;
	
	for(int i=3;i<=to;i++)
	{
		if( max_sum < sum[i] )
		{
			max_sum = sum[i];
			max_sum_index = i;
		}
	}
	cout<<max_sum_index<<endl;
	
	return	0;
}
