#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_DAYS	(100000+1)

int	temperature[MAX_NUM_OF_DAYS];

int	main(void)
{
	int	N,K,max_sum,current_sum;
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>temperature[i];
	}
	
	current_sum = 0;
	
	for(int i=1;i<=K;i++)
	{
		current_sum += temperature[i];
	}
	max_sum = current_sum;
	
	for(int i=K+1,prev=1;i<=N;i++,prev++)
	{
		current_sum = current_sum-temperature[prev]+temperature[i];
		max_sum = max(max_sum,current_sum);
	}
	cout<<max_sum<<endl;
	
	return	0;
}
