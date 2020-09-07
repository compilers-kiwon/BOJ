#include	<iostream>

using namespace	std;

#define	MAX_SIZE	200
#define	START		0

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	LEFT	0
#define	DOWN	1
#define	RIGHT	2
#define	UP		3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
}adj[MAX_DIR] = {{0,-1},{1,0},{0,1},{-1,0}};

void	place_box(int num_of_box,Pos* p,int& w,int& h)
{
	int	min_row,max_row,min_col,max_col;
	
	min_row = max_row = min_col = max_col = START;
	
	for(int i=1;i<num_of_box;i++)
	{
		int		n,d;
		int&	row = p[i].first;
		int&	col = p[i].second;
		
		cin>>n>>d;
		
		row = p[n].first+adj[d].d_row;
		col = p[n].second+adj[d].d_col;
		
		min_row = min(min_row,row);
		max_row = max(max_row,row);
		min_col = min(min_col,col);
		max_col = max(max_col,col);
	}
	
	w = max_col-min_col+1;
	h = max_row-min_row+1;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N,width,height;
		Pos	p[MAX_SIZE];
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		p[START] = make_pair(START,START);
		place_box(N,p,width,height);
		
		cout<<width<<' '<<height<<'\n';
	}
	
	return	0;
}
