#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int		N,M;
char	grid[MAX_SIZE][MAX_SIZE+1];
char	convert_table[0x100];

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
	}
}

void	init(void)
{
	convert_table['.'] = '.';
	convert_table['O'] = 'O';
	convert_table['-'] = '|';
	convert_table['|'] = '-';
	convert_table['/'] = '\\';
	convert_table['\\'] = '/';
	convert_table['^'] = '<';
	convert_table['<'] = 'v';
	convert_table['v'] = '>';
	convert_table['>'] = '^';
}

void	print(void)
{
	for(int row=M;row>=1;row--)
	{
		for(int col=1;col<=N;col++)
		{
			cout<<convert_table[grid[col][row]];
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	init();
	print();
	
	return	0;
}
