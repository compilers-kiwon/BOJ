#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	20

int		R,C;
string	puzzle[MAX_SIZE+1];

int	main(void)
{
	scanf("%d %d",&R,&C);
	
	for(int row=0;row<R;row++)
	{
		cin>>puzzle[row];
		puzzle[row].push_back('#');
	}
	puzzle[R].resize(C,'#');
	
	string	first_word(MAX_SIZE+1,'z'),init(MAX_SIZE+1,'z');
	
	for(int row=0;row<R;row++)
	{
		string	w;
		
		for(int col=0;col<puzzle[row].size();col++)
		{
			if( puzzle[row][col]=='#' )
			{
				if( !w.empty() )
				{
					if( w.length() > 1 )
					{
						first_word = min(first_word,w);
					}
					w.clear();
				}
			}
			else
			{
				w.push_back(puzzle[row][col]);
			}
		}
	}
	
	for(int col=0;col<C;col++)
	{
		string	w;
		
		for(int row=0;row<=R;row++)
		{
			if( puzzle[row][col]=='#' )
			{
				if( !w.empty() )
				{
					if( w.length() > 1 )
					{
						first_word = min(first_word,w);
					}
					w.clear();
				}
			}
			else
			{
				w.push_back(puzzle[row][col]);
			}
		}
	}
	
	if( first_word != init )
	{
		cout<<first_word<<'\n';
	}
	
	return	0;
}
