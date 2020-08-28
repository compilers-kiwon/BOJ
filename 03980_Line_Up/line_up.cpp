#include	<iostream>
#include	<vector>

using namespace	std;

#define	NUM_OF_POSITION	11
#define	NUM_OF_PLAYER	11

typedef	pair<int,int>	Player;	// first:position, second:ability

void	build_line_up(vector<bool>& position,vector<Player>* player_info,
					  int current_player_index,int current_ability,int& max_ability)
{
	if( current_player_index > NUM_OF_PLAYER )
	{
		max_ability = max(max_ability,current_ability);
		return;
	}
	
	vector<Player>&	current_player_info = player_info[current_player_index];
	
	for(int i=0;i<current_player_info.size();i++)
	{
		int	current_player_position,current_player_ability;
		
		current_player_position = current_player_info[i].first;
		current_player_ability = current_player_info[i].second;
		
		if( position[current_player_position] == false )
		{
			position[current_player_position] = true;
			
			build_line_up(position,player_info,current_player_index+1,
						  current_ability+current_player_ability,max_ability);
						  
			position[current_player_position] = false;
		}
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		vector<bool>	position(NUM_OF_POSITION+1,false);
		vector<Player>	player[NUM_OF_PLAYER+1];
		
		for(int i=1;i<=NUM_OF_PLAYER;i++)
		{
			for(int j=1;j<=NUM_OF_POSITION;j++)
			{
				int	s;
				
				cin>>s;
				
				if( s != 0 )
				{
					player[i].push_back(make_pair(j,s));
				}
			}
		}
		
		int	max_ability;
		
		max_ability = 0;
		build_line_up(position,player,1,0,max_ability);
		cout<<max_ability<<endl;
		
		T--;
	}
	
	return	0;
}
