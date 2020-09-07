#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	col_word,row_word;
	
	cin>>col_word>>row_word;
	
	string	puzzle[row_word.length()];
	
	for(int i=0;i<row_word.length();i++)
	{
		puzzle[i].resize(col_word.length(),'.');
	}
	
	int		row,col;
	bool	found;
	
	found = false;
	
	for(int i=0;i<col_word.length();i++)
	{
		for(int j=0;j<row_word.length();j++)
		{
			if( col_word[i] == row_word[j] )
			{
				col = i;
				row = j;
				found = true;
				break;
			}
		}
		
		if( found == true )
		{
			break;
		}
	}
	
	puzzle[row] = col_word;
	
	for(int i=0;i<row_word.length();i++)
	{
		puzzle[i][col] = row_word[i];
	}
	
	for(int i=0;i<row_word.length();i++)
	{
		cout<<puzzle[i]<<endl;
	}
	
	return	0;
}
