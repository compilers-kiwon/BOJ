#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	TEAM_A		0
#define	TEAM_B		1
	
int	main(void)
{
	int				A,B,G,score[2];
	map<string,int>	player;
	
	cin>>A>>B>>G;
	
	for(int i=1;i<=A;i++)
	{
		string	p;
		
		cin>>p;
		player[p] = TEAM_A;
	}
	
	for(int i=1;i<=B;i++)
	{
		string	p;
		
		cin>>p;
		player[p] = TEAM_B;
	}
	
	score[TEAM_A] = score[TEAM_B] = 0;
	
	for(int i=1;i<=G;i++)
	{
		string	p;
		
		cin>>p;
		score[player[p]]++;
	}
	
	if( score[TEAM_A] == score[TEAM_B] )
	{
		cout<<"TIE\n";
	}
	else
	{
		if( score[TEAM_A] > score[TEAM_B] )
		{
			cout<<"A\n";
		}
		else
		{
			cout<<"B\n";
		}
	}
	
	return	0;
}
