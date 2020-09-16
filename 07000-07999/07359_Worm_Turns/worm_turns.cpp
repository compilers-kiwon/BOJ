#include	<iostream>
#include	<string>
#include	<list>

using namespace	std;

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	INIT_HEAD_COL		30
#define	INIT_TAIL_COL		11
#define	INIT_WORM_ROW		25
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MAX_DIR				4
#define	GET_DIR(D)			((D)=='N'?0:(D)=='S'?1:(D)=='W'?2:3)
#define	GRID_SIZE			50

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

bool	ran_into_itself(list<Pos>& worm)
{
	list<Pos>::iterator	w,head;
	
	w = head = worm.begin();
	w++;
	
	for(;w!=worm.end();w++)
	{
		if( head->first==w->first && head->second==w->second )
		{
			return	true;
		}
	}
	
	return	false;
}

void	init(list<Pos>& worm,string& moves)
{
	for(int col=INIT_HEAD_COL;col>=INIT_TAIL_COL;col--)
	{
		worm.push_back(make_pair(INIT_WORM_ROW,col));
	}
	
	cin>>moves;
}

void	worm_move(list<Pos>& worm,string& moves)
{
	for(int i=0;i<moves.length();i++)
	{
		char&	m = moves[i];
		int		adj_row,adj_col;
		
		adj_row = worm.begin()->first+adj[GET_DIR(m)].d_row;
		adj_col = worm.begin()->second+adj[GET_DIR(m)].d_col;
		
		if( !IN_RANGE(1,adj_row,GRID_SIZE) || !IN_RANGE(1,adj_col,GRID_SIZE) )
		{
			cout<<"The worm ran off the board on move "<<i+1<<".\n";
			return;
		}
		
		worm.insert(worm.begin(),make_pair(adj_row,adj_col));
		worm.pop_back();
		
		if( ran_into_itself(worm) == true )
		{
			cout<<"The worm ran into itself on move "<<i+1<<".\n";
			return;
		}
	}
	
	cout<<"The worm successfully made all "<<moves.length()<<" moves.\n";
}

int		main(void)
{
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		list<Pos>	worm;
		string		moves;
		
		init(worm,moves);
		worm_move(worm,moves);
	}
	
	return	0;
}
