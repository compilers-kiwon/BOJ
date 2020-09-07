#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

typedef	pair<char,int>	Board;

void	init(vector<Board>& board)
{
	string	p;
	char	prev;
	int		cnt;
	
	cin>>p;
	p.push_back(' ');
	
	prev = p[0];
	cnt = 1;
	
	for(int i=1;i<p.length();i++)
	{
		if( p[i] == prev )
		{
			cnt++;
		}
		else
		{
			board.push_back(make_pair(prev,cnt));
			prev = p[i];
			cnt = 1;
		}
	}
}

bool	fill_board(vector<Board>& b,string& str)
{
	for(int i=0;i<b.size();i++)
	{
		char&	c = b[i].first;
		int&	cnt = b[i].second;
		
		if( c == '.' )
		{
			for(int j=1;j<=cnt;j++)
			{
				str.push_back('.');
			}
		}
		else
		{
			if( cnt%2 == 1 )
			{
				return	false;
			}
			
			for(int j=1,to=cnt/4;j<=to;j++)
			{
				str += "AAAA";
			}
			
			if( cnt%4 != 0 )
			{
				str += "BB";
			}
		}
		
	}
	
	return	true;
}

int		main(void)
{
	string			final;
	vector<Board>	board;
	
	init(board);
	
	if( fill_board(board,final) == false )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<final<<'\n';
	}
	
	return	0;
}
