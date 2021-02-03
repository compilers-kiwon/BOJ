#include	<iostream>
#include	<algorithm>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	NONE		0

int				N,U[MAX_SIZE];
map<int,bool>	sum_table;

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>U[i];
	}
}

void	init(void)
{
	sort(&U[1],&U[N+1]);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=i;j<=N;j++)
		{
			sum_table[U[i]+U[j]] = true;
		}
	}
}

int		find_max_sum(void)
{
	int ret;
	
	ret = NONE;
	
	for(int i=N;i>=1&&ret==NONE;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			int	diff;
			
			diff = U[i]-U[j];
			
			if( sum_table[diff] == true )
			{
				ret = U[i];
				break;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	init();
	
	cout<<find_max_sum()<<'\n';
	
	return	0;
}
