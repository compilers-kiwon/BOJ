#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	NUM_OF_PLAYER	2
#define	GRID_SIZE		9

#define	next_player(p)	(((p)+1)%NUM_OF_PLAYER)
#define	char2int(c)		((int)((c)-'0'))

const int		value[NUM_OF_PLAYER] = {-1,1};

bool	input(int& player,vector<int>& place)
{
	string	in;
	
	getline(cin,in);
	
	char&	c = in[0];
	
	if( c == '#' )
	{
		return	false;
	}
	
	if( c == 'X' )
	{
		player = 0;
	}
	else
	{
		player = 1;
	}
	
	for(int i=2;i<in.length();i+=2)
	{
		place.push_back(char2int(in[i]));
	}
	
	return	true;
}

bool	win(int* grid)
{
	int	sum;
	
	for(int i=1;i<=3;i++)
	{
		sum = grid[i]+grid[i+3]+grid[i+6];
		
		if( sum==-3 || sum==3 )
		{
			return	true;
		}
	}
	
	for(int i=1;i<=7;i+=3)
	{
		sum = grid[i]+grid[i+1]+grid[i+2];
		
		if( sum==-3 || sum==3 )
		{
			return	true;
		}
	}
	
	sum = grid[1]+grid[5]+grid[9];
	
	if( sum==-3 || sum==3 )
	{
		return	true;
	}
	
	sum = grid[3]+grid[5]+grid[7];
	
	if( sum==-3 || sum==3 )
	{
		return	true;
	}
	
	return	false;
}

int		main(void)
{
	for(;;)
	{
		int			p,grid[GRID_SIZE+1];
		int			winner;
		vector<int>	in;
		
		if( input(p,in) == false )
		{
			break;
		}
		
		for(int i=1;i<=GRID_SIZE;i++)
		{
			grid[i] = 0;
		}
		
		winner = -1;
		
		for(int i=0;i<in.size();i++)
		{
			grid[in[i]] = value[p];
			
			if( win(grid) == true )
			{
				winner = p;
				break;
			}
			
			p = next_player(p);
		}
		
		switch(winner)
		{
			case	-1:
				cout<<"Draw\n";
				break;
			case	0:
				cout<<"X\n";
				break;
			case	1:
				cout<<"O\n";
				break;
			default:
				break;
		}
	}
	
	return	0;
}
