#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE			100
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_WINDOW_INFO	Window;
struct	_WINDOW_INFO
{
	string			title;
	vector<string>	screen;
};

int		N,M;
char	grid[MAX_SIZE][MAX_SIZE+1];

void	input(void)
{
	cin>>N>>M;
	
	for(int row=0;row<N;row++)
	{
		cin>>&grid[row][0];
	}
}

void	find_window(int row,int col,Window& w)
{
	string	str,t;
	int		r,c,len;
	
	// 1. get the first line
	str.push_back('+');
	grid[row][col] = '.';
	
	for(c=col+1;grid[row][c]!='+';c++)
	{
		char&	d = grid[row][c];
		
		if( IN_RANGE('a',d,'z') == true )
		{
			t.push_back(d);
		}
		
		str.push_back(d);
		d = '.';
	}
	
	str.push_back('+');
	grid[row][c] = '.';
	
	w.title = t;
	len = str.length();
	w.screen.push_back(str);
	
	// 2. get the middle lines
	for(r=row+1;grid[r][col]!='+';r++)
	{
		str.clear();
		
		for(c=col;c<col+len;c++)
		{
			str.push_back(grid[r][c]);
			grid[r][c] = '.';
		}
		
		w.screen.push_back(str);
	}
	
	// 3. get the bottom line
	str.clear();
	
	for(c=col;c<col+len;c++)
	{
		str.push_back(grid[r][c]);
		grid[r][c] = '.';
	}
	
	w.screen.push_back(str);
}

void	get_windows(vector<Window>& windows)
{
	for(int row=0;row<N;row++)
	{
		for(int col=0;col<M;col++)
		{
			if( grid[row][col] == '+' )
			{
				Window	w;
				
				find_window(row,col,w);
				windows.push_back(w);
			}
		}
	}
}

bool	is_less(const Window& w1,const Window& w2)
{
	return	(w1.title<w2.title);
}

void	draw_window(int s_row,int s_col,Window& w)
{
	for(int row=0;row<w.screen.size();row++)
	{
		string&	str = w.screen[row];
		
		for(int col=0;col<str.length();col++)
		{
			grid[s_row+row][s_col+col] = str[col];
		}
	}
}

int		main(void)
{
	vector<Window>	w;
	
	input();
	get_windows(w);
	sort(w.begin(),w.end(),is_less);
	
	for(int row=0,col=0,i=0;i<w.size();i++,row++,col++)
	{
		draw_window(row,col,w[i]);
	}
	
	for(int row=0;row<N;row++)
	{
		cout<<&grid[row][0]<<'\n';
	}
	
	return	0;
}
