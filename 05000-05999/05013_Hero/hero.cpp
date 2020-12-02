#include	<iostream>
#include	<string>

using namespace std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n,cnt_of_wins;
	
	cin>>n;
	cnt_of_wins = 0;
	
	for(int i=1;i<=n;i++)
	{
		string	battle;
		bool	defeat;
		
		cin>>battle;
		defeat = false;
		
		for(int j=1;j<battle.length()&&defeat!=true;j++)
		{
			char&	current = battle[j];
			char&	previous = battle[j-1];
			
			if( previous=='C' && current=='D' )
			{
				defeat = true;
			}
		}
		
		if( defeat == false )
		{
			cnt_of_wins++;
		}
	}
	
	cout<<cnt_of_wins<<'\n';
	
	return	0;
}
