#include	<iostream>

using namespace	std;

#define	SAME		0
#define	FIRST_WIN	1
#define	SECOND_WIN	2

#define	BUF_LEN	10

int	main(void)
{
	int	N;
	int	prev_win_team,prev_score_time;
	int	first_team_score,second_team_score,first_team_win_time,second_team_win_time;
	
	prev_win_team = SAME;
	prev_score_time = 0;
	first_team_score = second_team_score = first_team_win_time = second_team_win_time = 0;
	
	scanf("%d",&N);getchar();
	
	while(N>0)
	{
		char	buf[BUF_LEN+1];
		int		team,min,sec,time,diff_time;
		
		fgets(buf,BUF_LEN,stdin);
		buf[4] = ' ';
		
		sscanf(buf,"%d %d %d",&team,&min,&sec);
		time = min*60+sec;
		diff_time = time-prev_score_time;
		
		if( prev_win_team == FIRST_WIN )
		{
			first_team_win_time += diff_time;
		}
		else if( prev_win_team == SECOND_WIN )
		{
			second_team_win_time += diff_time;
		}
		prev_score_time = time;
		
		if( team == 1 )
		{
			first_team_score++;
		}
		else
		{
			second_team_score++;
		}
		
		if( first_team_score > second_team_score )
		{
			prev_win_team = FIRST_WIN;
		}
		else if( first_team_score < second_team_score )
		{
			prev_win_team = SECOND_WIN;
		}
		else
		{
			prev_win_team = SAME;
		}
		
		N--;
	}
	
	int	end;
	
	end = 48*60-prev_score_time;
		
	if( prev_win_team == FIRST_WIN )
	{
		first_team_win_time += end;
	}
	else if( prev_win_team == SECOND_WIN )
	{
		second_team_win_time += end;
	}
		
	printf("%02d:%02d\n",first_team_win_time/60,first_team_win_time%60);
	printf("%02d:%02d\n",second_team_win_time/60,second_team_win_time%60);

	return	0;
}
