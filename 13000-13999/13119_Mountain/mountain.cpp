#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(200000+1)

int		N,M,X,H[MAX_SIZE];
string	map[MAX_SIZE];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>X;
	
	for(int i=0;i<M;i++)
	{
		cin>>H[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		map[i].resize(M,'.');
	}
}

void	draw_map(void)
{
	for(int width=0;width<M;width++)
	{
		for(int h=1;h<=H[width];h++)
		{
			map[h][width] = '#';
		}
		
		if( map[X][width] == '#' )
		{
			map[X][width] = '*';
		}
		else
		{
			map[X][width] = '-';
		}
		
		if( width%3 == 2 )
		{
			for(int h=H[width]+1;h<X;h++)
			{
				map[h][width] = '|';
			}
		}
	}
}

int		main(void)
{
	init();
	draw_map();
	
	for(int h=N;h>=1;h--)
	{
		cout<<map[h]<<'\n';
	}
	
	return	0;
}
