#include	<iostream>
#include	<string>

using namespace	std;

#define	KING				0
#define	QUEEN				1
#define	ROOK				2
#define	BISHOP				3
#define	KNIGHT				4
#define	PAWN				5
#define	MAX_KINDS_OF_PIECES	6

int	pieces[MAX_KINDS_OF_PIECES];

void	init_pieces(void)
{
	pieces[KING] = 1;
	pieces[QUEEN] = 1;
	pieces[ROOK] = 2;
	pieces[BISHOP] = 2;
	pieces[KNIGHT] = 2;
	pieces[PAWN] = 8;
}

int		main(void)
{
	init_pieces();
	
	for(int i=KING;i<=PAWN;i++)
	{
		int	p;
		
		cin>>p;
		cout<<pieces[i]-p<<' ';
	}
	cout<<endl;
	
	return	0;
}
