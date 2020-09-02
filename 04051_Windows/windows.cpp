#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_WINDOWS	(100+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_WINDOW_INFO	Window;
struct	_WINDOW_INFO
{
	int	up,down,left,right;
};

int		n;
Window	windows[MAX_NUM_OF_WINDOWS];

void	get_windows(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int&	r = windows[i].up;
		int&	c = windows[i].left;
		int		w,h;
		
		cin>>r>>c>>w>>h;
		windows[i].down = r+(h-1);
		windows[i].right = c+(w-1);
	}
}	

int		find_window(int row,int col)
{
	int	ret;
	
	ret = 0;
	
	for(int i=1;i<=n;i++)
	{
		int&	left = windows[i].left;
		int&	right = windows[i].right;
		int&	up = windows[i].up;
		int&	down = windows[i].down;
		
		if( IN_RANGE(left,col,right) && IN_RANGE(up,row,down) )
		{
			ret = i;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int d=1;;d++)
	{
		get_windows();
		
		if( n == 0 )
		{
			break;
		}
		
		int	m;
		
		cin>>m;
		cout<<"Desktop "<<d<<":\n";
		
		for(int i=1;i<=m;i++)
		{
			int	row,col,w;
			
			cin>>row>>col;
			w = find_window(row,col);
			
			if( w != 0 )
			{
				cout<<"window "<<w<<'\n';
			}
			else
			{
				cout<<"background\n";
			}
		}
	}
	
	return	0;
}
