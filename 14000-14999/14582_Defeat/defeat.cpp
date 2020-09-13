#include	<iostream>

using namespace	std;

#define	NUM_OF_INNING	9

int	main(void)
{
	int	score[NUM_OF_INNING+1][2];
	
	for(int i=1;i<=NUM_OF_INNING;i++)
	{
		cin>>score[i][0];
	}
	
	for(int i=1;i<=NUM_OF_INNING;i++)
	{
		cin>>score[i][1];
	}
	
	int		woolim_score,startlink_score;
	bool	woolim_leads;
	
	woolim_score = startlink_score = 0;
	woolim_leads = false;
	
	for(int i=1;i<=NUM_OF_INNING;i++)
	{
		woolim_score += score[i][0];
		
		if( woolim_score > startlink_score )
		{
			woolim_leads = true;
		}
		
		startlink_score += score[i][1];
	}
	
	if( woolim_leads == true )
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	return	0;
}
