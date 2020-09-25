#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(10000+1)
#define	MAX_NUM_OF_DIAMONDS	(1000+1)
#define	NONE				0

int	N,K;
int	size[MAX_NUM_OF_DIAMONDS];
int	num_of_diamonds[MAX_SIZE];

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>size[i];
		num_of_diamonds[size[i]]++;
	}
	
	int	max_num_of_displayed;
	
	max_num_of_displayed = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	cnt;
		
		cnt = 0;
		
		for(int j=size[i];j<=min(MAX_SIZE-1,size[i]+K);j++)
		{
			cnt += num_of_diamonds[j];
		}
		
		max_num_of_displayed = max(max_num_of_displayed,cnt);
	}
	
	cout<<max_num_of_displayed<<'\n';
	
	return	0;
}
