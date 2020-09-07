#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	WALL		'#'

char			puzzle[MAX_SIZE][MAX_SIZE+1];
pair<bool,bool>	visited[MAX_SIZE][MAX_SIZE];
int				R,C;

void	input(void)
{
	scanf("%d %d",&R,&C);

	for(int i=1;i<=R;i++)
	{
		scanf("%s",&puzzle[i][1]);	
	}	
}

int		main(void)
{
	string	first_word(MAX_SIZE,'z');
	
	input();
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( puzzle[row][col] != WALL )
			{
				if( visited[row][col].first == false )
				{
					string	tmp;
					
					for(int i=row;i<=R;i++)
					{
						if( puzzle[i][col] == WALL )
						{
							break;
						}
						tmp.push_back(puzzle[i][col]);
						visited[i][col].first = true;
					}
					
					if( tmp.length()>=2 && tmp<first_word )
					{
						first_word = tmp;
					}
				}
				
				if( visited[row][col].second == false )
				{
					string	tmp;
					
					for(int i=col;i<=C;i++)
					{
						if( puzzle[row][i] == WALL )
						{
							break;
						}
						tmp.push_back(puzzle[row][i]);
						visited[row][i].second = true;
					}
					
					if( tmp.length()>=2 && tmp<first_word )
					{
						first_word = tmp;
					}
				}
			}
		}
	}
	
	cout<<first_word<<endl;
	
	return	0;
}
