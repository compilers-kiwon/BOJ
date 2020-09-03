#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_CARDS	100

#define	USED		0
#define	SANGGUEN	1
#define	GUENSANG	2

#define	SANGGUEN_TURN	0
#define	GUENSANG_TURN	1
#define	NEXT_TURN(t)	(((t)+1)%2)

int	card[MAX_NUM_OF_CARDS*2+1];

int	main(void)
{
	int	n,num_of_sanguen_card,num_of_guensang_card,top,turn;
	
	cin.sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=1;i<=2*n;i++)
	{
		card[i] = GUENSANG;
	}
	
	for(int i=1;i<=n;i++)
	{
		int	c;
		
		cin>>c;
		card[c] = SANGGUEN;
	}
	
	num_of_sanguen_card = num_of_guensang_card = n;
	top = 0;
	turn = SANGGUEN_TURN;
	
	while( num_of_sanguen_card!=0 && num_of_guensang_card!=0 )
	{
		int current_player;
		
		if( turn == SANGGUEN_TURN )
		{
			current_player = SANGGUEN;
		}
		else
		{
			current_player = GUENSANG;
		}
		
		int	card_to_be_removed;
		
		card_to_be_removed = 0;
		
		for(int i=top+1;i<=2*n;i++)
		{
			if( card[i] == current_player )
			{
				card_to_be_removed = i;
				break;
			}
		}
		
		if( card_to_be_removed != 0 )
		{
			card[card_to_be_removed] = USED;
			top = card_to_be_removed;
			
			if( current_player == SANGGUEN )
			{
				num_of_sanguen_card--;
			}
			else
			{
				num_of_guensang_card--;
			}
		}
		else
		{
			top = 0;
		}
		
		turn = NEXT_TURN(turn);
	}
	
	cout<<num_of_guensang_card<<'\n'<<num_of_sanguen_card<<'\n';

	return	0;
}
