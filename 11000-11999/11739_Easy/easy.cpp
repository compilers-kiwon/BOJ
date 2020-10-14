#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_JUDGES	(10+1)
#define	INF					50

int			n,k;
queue<int>	problem[MAX_NUM_OF_JUDGES];

void	input(void)
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		int	p;
		
		cin>>p;
		
		for(int j=1;j<=p;j++)
		{
			int	h;
			
			cin>>h;
			problem[i].push(h);
		}
	}
}

int		select_problem(void)
{
	int	ret;
	
	for(ret=0;k!=0;)
	{
		for(int i=1;i<=n&&k!=0;i++)
		{
			int	proposed;
			
			if( problem[i].empty() == true )
			{
				proposed = INF;
			}
			else
			{
				proposed = problem[i].front();
				problem[i].pop();
			}
				
			if( proposed!=INF && proposed < ret )
			{
				continue;
			}
			
			ret += proposed;
			k--;
		}
	}

	return	ret;
}

int		main(void)
{
	input();
	cout<<select_problem()<<'\n';
	
	return	0;
}
