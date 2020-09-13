#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_ROW	26
#define	MAX_COL	500

#define	GET_ROW_INDEX(str)	((int)((str)[0]-'a'))
#define	GET_COL_INDEX(str)	((str).length())

vector<string>	table[MAX_ROW][MAX_COL+1];

int	main(void)
{
	int	N,M,cnt;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		string	s;
		
		cin>>s;
		table[GET_ROW_INDEX(s)][GET_COL_INDEX(s)].push_back(s);
	}
	
	cnt = 0;
	
	for(int i=1;i<=M;i++)
	{
		string	s;
		int		row_index,col_index;
		bool	found;
		
		cin>>s;
		row_index = GET_ROW_INDEX(s);
		col_index = GET_COL_INDEX(s);
		found = false;
		
		for(int n=col_index;n<=MAX_COL;n++)
		{
			vector<string>&	words = table[row_index][n];
			
			for(int j=0;j<words.size();j++)
			{
				found = true;
				
				for(int k=0;k<col_index;k++)
				{
					if( words[j][k] != s[k] )
					{
						found = false;
						break;
					}
				}
				
				if( found == true )
				{
					break;
				}
			}
			
			if( found == true )
			{
				cnt++;
				break;
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
