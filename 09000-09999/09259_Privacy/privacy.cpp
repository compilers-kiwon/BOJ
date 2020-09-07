#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_OPTIONS	(100+1)
#define	MAX_BUDGET			(100+1)
#define	MAX_PRIVACY_LOSS	(100+1)

int	n,B,P;
int	table[MAX_NUM_OF_OPTIONS][MAX_BUDGET][MAX_PRIVACY_LOSS];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	max_benefit;
		
		cin>>n>>B>>P;
		max_benefit = 0;
		
		for(int option=1;option<=n;option++)
		{
			for(int cost=0;cost<=B;cost++)
			{
				fill(&table[option][cost][0],&table[option][cost][P+1],0);
			}
		}
		
		for(int current_option=1;current_option<=n;current_option++)
		{
			int	current_benefit,current_cost,current_loss;
			
			cin>>current_benefit>>current_cost>>current_loss;
			
			// 1. select current option
			if( current_cost<=B && current_loss<=P )
			{
				table[current_option][current_cost][current_loss] = current_benefit;
			}
			
			// 2. check prev option
			for(int cost=0;cost<=B;cost++)
			{
				for(int loss=0;loss<=P;loss++)
				{
					// 2-1. inherit prev benefit as itself
					table[current_option][cost][loss] = 
						max(table[current_option][cost][loss],table[current_option-1][cost][loss]);
						
					// 2-2. check constraints and select current option
					if( cost+current_cost<=B && loss+current_loss<=P )
					{
						table[current_option][cost+current_cost][loss+current_loss] =
							max(table[current_option-1][cost][loss]+current_benefit,table[current_option][cost+current_cost][loss+current_loss]);
					}
					
					max_benefit = max(max_benefit,table[current_option][cost][loss]);
				}
			}
		}
		
		cout<<"Data Set "<<k<<":\n"<<max_benefit<<"\n\n";
	}
	
	return	0;
}
