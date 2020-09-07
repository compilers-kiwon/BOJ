#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(40+1)

#define	OIL		'X'
#define	HARD	'H'
#define	SOFT	'S'

#define	HARD_ROCK_COST	3
#define	SOFT_ROCK_COST	1

#define	get_cost(r)	(((r)==HARD)?HARD_ROCK_COST:SOFT_ROCK_COST)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int		h,w;
		bool	found[MAX_SIZE];
		int		sum_of_cost[MAX_SIZE];
		
		cin>>h>>w;
		
		fill(&found[1],&found[w+1],false);
		fill(&sum_of_cost[1],&sum_of_cost[w+1],0);
		
		for(int i=1;i<=h;i++)
		{
			char	buf[MAX_SIZE+1];
			
			cin>>&buf[1];
			
			for(int j=1;j<=w;j++)
			{
				if( found[j] == true )
				{
					continue;
				}
				
				if( buf[j] == OIL )
				{
					found[j] = true;
				}
				else
				{
					sum_of_cost[j] += get_cost(buf[j]);
				}
			}
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=1;i<=w;i++)
		{
			if( found[i] == false )
			{
				cout<<'N';
			}
			else
			{
				cout<<sum_of_cost[i];
			}
			
			if( i == w )
			{
				cout<<"\n\n";
			}
			else
			{
				cout<<' ';
			}
		}
	}
	
	return	0;
}
