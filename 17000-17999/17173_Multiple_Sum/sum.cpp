#include	<iostream>

using namespace	std;

#define	MAX_NUM	1000

int		N,M,K[MAX_NUM];
bool	used[MAX_NUM+1];

void	find_multiple(int n,int& sum)
{
	for(int i=n;i<=N;i+=n)
	{
		if( used[i] == false )
		{
			used[i] = true;
			sum += i;
		}
	}	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		cin>>K[i];
	}
	
	int	sum = 0;
	
	for(int i=1;i<=M;i++)
	{
		find_multiple(K[i],sum);
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
