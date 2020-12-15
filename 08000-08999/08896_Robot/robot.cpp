#include	<iostream>
#include	<string>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10+1)

#define	ROCK		0
#define	PAPER		1
#define	SCISSORS	2
#define	MAX_TYPE	3

#define	NO_WINNER	MAX_TYPE

int		N;
string	r[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>r[i];
	}
}

int		find_winner(vector<int>* robot)
{
	if( robot[ROCK].empty() && !robot[SCISSORS].empty() )
	{
		return	SCISSORS;
	}
	
	if( robot[PAPER].empty() && !robot[ROCK].empty() )
	{
		return	ROCK;
	}
	
	if( robot[SCISSORS].empty() && !robot[PAPER].empty() )
	{
		return	PAPER;
	}
	
	return	NO_WINNER;
}

int		simulate(int max_round)
{
	int			ret;
	queue<int>	available_robot;
	
	ret = N+1;
	
	for(int i=1;i<=N;i++)
	{
		available_robot.push(i);
	}
	
	for(int round=0;round<=max_round;round++)
	{
		if( available_robot.size() == 1 )
		{
			ret = available_robot.front();
			break;
		}
		
		if( round == max_round )
		{
			break;
		}
		
		vector<int>	robot[MAX_TYPE];
		
		for(int i=1,size=available_robot.size();i<=size;i++)
		{
			char&	c = r[available_robot.front()][round];
			
			switch(c)
			{
				case	'R':
					robot[ROCK].push_back(available_robot.front());
					break;
				case	'P':
					robot[PAPER].push_back(available_robot.front());
					break;
				case	'S':
					robot[SCISSORS].push_back(available_robot.front());
					break;
				default:
					// do nothing
					break;
			}
			
			available_robot.pop();
		}
		
		int	winner;
		
		winner = find_winner(robot);
		
		if( winner == NO_WINNER )
		{
			for(int i=0;i<MAX_TYPE;i++)
			{
				for(int j=0;j<robot[i].size();j++)
				{
					available_robot.push(robot[i][j]);
				}
			}
		}
		else
		{
			for(int j=0;j<robot[winner].size();j++)
			{
				available_robot.push(robot[winner][j]);
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	w;
		
		input();
		w = simulate(r[1].length());
		
		if( w > N )
		{
			cout<<"0\n";
		}
		else
		{
			cout<<w<<'\n';
		}
	}
	
	return	0;
}
