#include	<iostream>

using namespace	std;

#define	MAX_TIME_LEN	5
#define	SEC_PER_MIN		60

#define	HOME	'H'
#define	AWAY	'A'

#define	HOME_INDEX		0
#define	AWAY_INDEX		1
#define	MAX_NUM_OF_TEAM	2
#define	GET_INDEX(T)	(((T)==HOME)?HOME_INDEX:AWAY_INDEX)

#define	MAX_SIZE		(SEC_PER_MIN*32)
#define	NONE			-1

int	score_board[MAX_SIZE+1][MAX_NUM_OF_TEAM];

int		time2sec(char* time)
{
	int	m,s;
	
	if( time[1] == ':' )
	{
		time[1] = ' ';
	}
	else
	{
		time[2] = ' ';
	}
	
	sscanf(time,"%d %d",&m,&s);
	
	return	m*SEC_PER_MIN+s;
}

void	play_game(void)
{
	int	N,lead_time[MAX_NUM_OF_TEAM],current_lead_team;

	scanf("%d",&N);getchar();
	
	for(int i=1;i<=N;i++)
	{
		char	team,time[MAX_TIME_LEN+1];
		int		score,sec;
		
		scanf("%c %d %s",&team,&score,time);getchar();
		sec = time2sec(time);
		
		score_board[sec][GET_INDEX(team)] += score;
	}
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		score_board[i][HOME_INDEX] += score_board[i-1][HOME_INDEX];
		score_board[i][AWAY_INDEX] += score_board[i-1][AWAY_INDEX];
	}
	
	lead_time[HOME_INDEX] = lead_time[AWAY_INDEX] = 0;
	current_lead_team = NONE;
	
	for(int i=0;i<=MAX_SIZE;i++)
	{
		int	lead_team_at_moment;
		
		if( score_board[i][HOME_INDEX] == score_board[i][AWAY_INDEX] )
		{
			lead_team_at_moment = NONE;
		}
		else
		{
			if( score_board[i][HOME_INDEX] > score_board[i][AWAY_INDEX] )
			{
				lead_team_at_moment = HOME_INDEX;
			}
			else
			{
				lead_team_at_moment = AWAY_INDEX;
			}
		}
		
		if( current_lead_team != NONE )
		{
			lead_time[current_lead_team]++;
		}
		
		current_lead_team = lead_team_at_moment;
	}
	
	if( score_board[MAX_SIZE][HOME_INDEX] > score_board[MAX_SIZE][AWAY_INDEX] )
	{
		printf("H %d:%02d %d:%02d\n",lead_time[HOME_INDEX]/SEC_PER_MIN,lead_time[HOME_INDEX]%SEC_PER_MIN,
									 lead_time[AWAY_INDEX]/SEC_PER_MIN,lead_time[AWAY_INDEX]%SEC_PER_MIN);
	}
	else
	{
		printf("A %d:%02d %d:%02d\n",lead_time[HOME_INDEX]/SEC_PER_MIN,lead_time[HOME_INDEX]%SEC_PER_MIN,
									 lead_time[AWAY_INDEX]/SEC_PER_MIN,lead_time[AWAY_INDEX]%SEC_PER_MIN);
	}
}

int		main(void)
{
	play_game();
	
	return	0;
}
