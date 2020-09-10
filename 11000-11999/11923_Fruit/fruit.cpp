#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_FRUITS	(1000+1)

int	N,C,w[MAX_NUM_OF_FRUITS];

int	eat_fruit(int s)
{
	int	eaten,cnt;
	
	eaten = cnt = 0;
	
	for(int i=s;i<=N;i++)
	{
		if( eaten+w[i] <= C )
		{
			eaten += w[i];
			cnt++;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>C;
	
	for(int i=1;i<=N;i++)
	{
		cin>>w[i];
	}
	
	int	max_amount_of_fruits;
	
	max_amount_of_fruits = 0;
	
	for(int i=1;i<=N;i++)
	{
		max_amount_of_fruits = max(max_amount_of_fruits,eat_fruit(i));
	}
	
	cout<<max_amount_of_fruits<<'\n';
	
	return	0;
}
