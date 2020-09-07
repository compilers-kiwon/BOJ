#include	<iostream>

using namespace	std;

#define	MAX_LEN_OF_DATA	(100+1)

int	main(void)
{
	int N,K,max_temp,temp[MAX_LEN_OF_DATA];
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>temp[i];
	}
	
	max_temp = -100*MAX_LEN_OF_DATA;
	
	for(int i=1;i<=N-K+1;i++)
	{
		int	sum;
		
		sum = 0;
		
		for(int j=i;j<i+K;j++)
		{
			sum += temp[j];
		}
		
		max_temp = max(max_temp,sum);
	}
	
	cout<<max_temp<<endl;
	
	return	0;
}
