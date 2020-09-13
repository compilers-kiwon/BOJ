#include	<iostream>
#include	<map>
#include	<vector>

using namespace	std;

typedef	unsigned int	uint32;

#define	SCISSORS	1
#define	ROCK		2
#define	PAPER		3

#define	TEAM_A	1
#define	TEAM_B	2

map<uint32,uint32>	defeat;

vector<uint32>	A,B;
uint32			N,winner,cnt,max_cnt;

int	main(void)
{
	cin>>N;
	
	uint32	i;
	
	defeat[ROCK] = PAPER;
	defeat[PAPER] = SCISSORS;
	defeat[SCISSORS] = ROCK;
	
	for(i=1;i<=N;i++)
	{
		uint32	v;
		
		cin>>v;
		A.push_back(v);
	}
	
	for(i=1;i<=N;i++)
	{
		uint32	v;
		
		cin>>v;
		B.push_back(v);
	}
	
	if( defeat[A[0]] == B[0] )
	{
		winner = TEAM_B;		
	}
	else
	{
		winner = TEAM_A;		
	}
	
	cnt = 1;
	max_cnt = 0;
	
	for(i=1;i<N;i++)
	{
		if( winner == TEAM_A )
		{
			if(defeat[B[i]] == A[i] )
			{
				cnt++;
			}
			else
			{
				if( max_cnt < cnt )
				{
					max_cnt = cnt;
				}
				cnt = 1;
				winner = TEAM_B;
			}
		}
		else
		{
			if(defeat[A[i]] == B[i] )
			{
				cnt++;
			}
			else
			{
				if( max_cnt < cnt )
				{
					max_cnt = cnt;
				}
				cnt = 1;
				winner = TEAM_A;
			}
		}
	}
	cout<<max_cnt<<endl;
	
	return	0;
}


