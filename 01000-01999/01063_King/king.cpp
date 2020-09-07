#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	BOARD_SIZE	8
#define	IN_RANGE(n)	(1<=(n)&&(n)<=BOARD_SIZE)

typedef	struct	_POS_INFO	Pos;
struct	_POS_INFO
{
	int	row,col;
};

void	init_table(map<string,Pos>& table)
{
	char	col,row;
	int		c,r;
	
	for(col='A',c=1;col<='H';c++,col++)
	{
		for(row='1',r=8;row<='8';r--,row++)
		{
			string	p;
			
			p.push_back(col);
			p.push_back(row);
			
			table[p].row = r;
			table[p].col = c;
		}
	}
	
	table["R"].row = 0;
	table["R"].col = 1;
	
	table["L"].row = 0;
	table["L"].col = -1;
	
	table["B"].row = 1;
	table["B"].col = 0;
	
	table["T"].row = -1;
	table["T"].col = 0;
	
	table["RT"].row = -1;
	table["RT"].col = 1;
	
	table["LT"].row = -1;
	table["LT"].col = -1;
	
	table["RB"].row = 1;
	table["RB"].col = 1;
	
	table["LB"].row = 1;
	table["LB"].col = -1;
}

int		main(void)
{
	int				king_row,king_col,stone_row,stone_col,N;
	string			king_pos,stone_pos;
	map<string,Pos>	table;
	
	init_table(table);
	
	cin.sync_with_stdio(false);
	
	cin>>king_pos>>stone_pos>>N;
	
	king_row = table[king_pos].row;
	king_col = table[king_pos].col;
	
	stone_row = table[stone_pos].row;
	stone_col = table[stone_pos].col;
	
	for(int i=1;i<=N;i++)
	{
		int		adj_king_row,adj_king_col,adj_stone_row,adj_stone_col;
		string	mv;
		
		cin>>mv;
		
		adj_king_row = king_row+table[mv].row;
		adj_king_col = king_col+table[mv].col;
		
		if( IN_RANGE(adj_king_row) && IN_RANGE(adj_king_col) )
		{
			if( adj_king_row == stone_row && adj_king_col == stone_col )
			{
				adj_stone_row = stone_row+table[mv].row;
				adj_stone_col = stone_col+table[mv].col;
				
				if( IN_RANGE(adj_stone_row) && IN_RANGE(adj_stone_col) )
				{
					king_row = adj_king_row;
					king_col = adj_king_col;
					
					stone_row = adj_stone_row;
					stone_col = adj_stone_col;
				}
			}
			else
			{
				king_row = adj_king_row;
				king_col = adj_king_col;
			}
		}
	}
	
	map<string,Pos>::iterator	it;
	
	for(table["RB"].row = table["RB"].col = 0,it=table.begin();it!=table.end();it++)
	{
		if( it->second.row == king_row && it->second.col == king_col )
		{
			king_pos = it->first;
		}
		
		if( it->second.row == stone_row && it->second.col == stone_col )
		{
			stone_pos = it->first;
		}
	}
	
	cout<<king_pos<<'\n'<<stone_pos<<'\n';
	
	return	0;
}
