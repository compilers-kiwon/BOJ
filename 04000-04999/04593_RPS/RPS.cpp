#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	TIE					0
#define	PLAYER_1			1
#define	PLAYER_2			2
#define	MAX_NUM_OF_PLAYER	3

map< char,map<char,int> >	winner;

void	init(void)
{
	winner['R']['R'] = TIE;
	winner['R']['P'] = PLAYER_2;
	winner['R']['S'] = PLAYER_1;
	
	winner['P']['R'] = PLAYER_1;
	winner['P']['P'] = TIE;
	winner['P']['S'] = PLAYER_2;
	
	winner['S']['R'] = PLAYER_2;
	winner['S']['P'] = PLAYER_1;
	winner['S']['S'] = TIE;
}

int		main(void)
{
	init();
	
	for(;;)
	{
		string p1,p2;
		int		score[MAX_NUM_OF_PLAYER];
		
		cin>>p1>>p2;
		score[PLAYER_1] = score[PLAYER_2] = 0;
		
		if( p1=="E" && p2=="E" )
		{
			break;
		}
		
		for(int i=0;i<p1.length();i++)
		{
			score[winner[p1[i]][p2[i]]]++;
		}
		
		cout<<"P1: "<<score[PLAYER_1]<<"\nP2: "<<score[PLAYER_2]<<'\n';
	}
	
	return	0;
}
