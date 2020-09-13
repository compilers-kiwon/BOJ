#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_GAME	(100+1)

#define	HOOF		0
#define	PAPER		1
#define	SCISSORS	2
#define	MAX_GESTURE	3

typedef	pair<int,int>	Game;

const int win_gesture[MAX_GESTURE] = {PAPER,SCISSORS,HOOF};

int		N,gesture_map[MAX_GESTURE+1],gesture_used[MAX_GESTURE];
Game	g[MAX_NUM_OF_GAME];

bool	first_cow_win(int first_cow_gesture,int second_cow_gesture)
{
	bool	result;
	
	if( win_gesture[second_cow_gesture] == first_cow_gesture )
	{
		result = true;
	}
	else
	{
		result = false;
	}
	
	return	result;
}

void	simulate_game(int& max_num_of_wins)
{
	int	cnt,i;
	
	for(i=1,cnt=0;i<=N;i++)
	{
		if( first_cow_win(gesture_map[g[i].first],gesture_map[g[i].second]) == true )
		{
			cnt++;
		}
	}
	
	max_num_of_wins = max(max_num_of_wins,cnt);
}

void	build_gesture_map(int gesture_number,int& max_num_of_wins)
{
	if( gesture_number > MAX_GESTURE )
	{
		simulate_game(max_num_of_wins);
		return;
	}
	
	for(int i=HOOF;i<=SCISSORS;i++)
	{
		if( gesture_used[i] == false )
		{
			gesture_used[i] = true;
			gesture_map[gesture_number] = i;
			
			build_gesture_map(gesture_number+1,max_num_of_wins);
			
			gesture_used[i] = false;
		}
	}
}

int		main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>g[i].first>>g[i].second;	
	}
	
	int	max_num_of_wins;
	
	max_num_of_wins = 0;
	build_gesture_map(1,max_num_of_wins);
	
	cout<<max_num_of_wins<<'\n';
	
	return	0;	
}
