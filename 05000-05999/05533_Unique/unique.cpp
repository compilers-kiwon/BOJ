#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PLAYERS	(200+1)
#define	MAX_ROUND			3
#define	MAX_SCORE			100

int	main(void)
{
	int	N,player[MAX_NUM_OF_PLAYERS][MAX_ROUND+2],score[MAX_SCORE+1];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>player[i][1]>>player[i][2]>>player[i][3];
		player[i][4] = 0;
	}
	
	for(int i=1;i<=MAX_ROUND;i++)
	{
		for(int k=1;k<=MAX_SCORE;k++)
		{
			score[k] = 0;
		}
		
		for(int j=1;j<=N;j++)
		{
			int& s = player[j][i];
			
			if( score[s] == 0 )
			{
				score[s] = j;
			}
			else if( score[s] > 0 )
			{
				score[s] = -1;
			}
		}
		
		for(int k=1;k<=MAX_SCORE;k++)
		{
			if( score[k] > 0 )
			{
				player[score[k]][4] += k;
			}
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<player[i][4]<<endl;
	}
	
	return	0;
}
