#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	MORTAL	'O'
#define	MIRROR	'M'

#define	EAST	0
#define	NORTH	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

#define	get_dir(c)	((c)=='E'?EAST:(c)=='N'?NORTH:(c)=='S'?SOUTH:WEST)

int		v,o,m,mirror[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE];

const int		reflected[MAX_DIR] = {WEST,SOUTH,NORTH,EAST};
const string	dir_str[MAX_DIR] = {"east","north","south","west"};
const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{1,0},{0,1},{0,-1},{-1,0}};

typedef	pair<int,int>	Pos;	// first:x,second:y
typedef	vector<string>	Reflect;

void	init(void)
{
	for(int y=0;y<MAX_SIZE;y++)
	{
		for(int x=0;x<MAX_SIZE;x++)
		{
			grid[y][x] = ' ';
		}
	}
}

void	get_vampire_pos(vector<Pos>& vampire_pos)
{
	for(int i=1;i<=v;i++)
	{
		Pos	p;
		
		cin>>p.first>>p.second;
		vampire_pos.push_back(p);
	}
}

void	get_motal_pos(void)
{
	for(int i=1;i<=o;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		grid[y][x] = MORTAL;
	}
}

void	get_mirror_pos(void)
{
	for(int i=1;i<=m;i++)
	{
		char	d;
		int		x1,y1,x2,y2;
		
		cin>>d>>x1>>y1>>x2>>y2;
		
		for(int y=min(y1,y2);y<=max(y1,y2);y++)
		{
			for(int x=min(x1,x2);x<=max(x1,x2);x++)
			{
				grid[y][x] = MIRROR;
				mirror[y][x] = get_dir(d);
			}
		}
	}
}

void	find_reflected_mirror(int x,int y,Reflect& direction)
{
	for(int d=EAST;d<=WEST;d++)
	{
		int	adj_x = x;
		int	adj_y = y;
		
		for(;IN_RANGE(0,adj_x,MAX_SIZE)&&IN_RANGE(0,adj_y,MAX_SIZE);)
		{
			if( grid[adj_y][adj_x] == MORTAL )
			{
				break;
			}
			
			if( grid[adj_y][adj_x] == MIRROR )
			{
				if( mirror[adj_y][adj_x] == reflected[d] )
				{
					direction.push_back(dir_str[d]);
				}
				
				break;
			}
			
			adj_x += adj[d].dx;
			adj_y += adj[d].dy;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int c=1;;c++)
	{
		cin>>v>>o>>m;
		
		if( v==0 && o==0 && m==0 )
		{
			break;
		}
		
		init();
		cout<<"Case "<<c<<":\n";
		
		vector<Pos>	vampire;
		bool		none_flag;
		
		get_vampire_pos(vampire);
		get_motal_pos();
		get_mirror_pos();
		
		none_flag = true;
		
		for(int v=0;v<vampire.size();v++)
		{
			Reflect	r;
			
			find_reflected_mirror(vampire[v].first,vampire[v].second,r);
			
			if( r.size() != 0 )
			{
				none_flag = false;
				cout<<"vampire "<<v+1;
				
				for(int i=0;i<r.size();i++)
				{
					cout<<' '<<r[i];
				}
				cout<<'\n';
			}
		}
		
		if( none_flag == true )
		{
			cout<<"none\n";
		}
	}
	
	return	0;
}
