#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	MAX_HEIGHT	(30+1)
#define	MAX_WIDTH	(30+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	get_dir(c)			(((c)=='u')?UP:((c)=='d')?DOWN:((c)=='l')?LEFT:RIGHT)

int		h,w,s,n;
bool	visited[MAX_HEIGHT][MAX_WIDTH];

typedef	pair<int,int>	Pos;	// first:row,second:col

int		get_size_of_cavity(int row,int col)
{
	queue<Pos>	q;
	int			ret;
	
	visited[row][col] = true;
	q.push(make_pair(row,col));
	
	for(ret=0;!q.empty();ret++)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,h) || !IN_RANGE(1,adj_col,w) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] == false )
			{
				visited[adj_row][adj_col] = true;
				q.push(make_pair(adj_row,adj_col));
			}
		}
	}
	
	return	ret;
}

void	mark_patrol(string& path)
{
	int	row,col;
	
	row=h;col=1;
	visited[row][col] = true;
	
	for(int i=0;i<path.length();i++)
	{
		int	d;
		
		d = get_dir(path[i]);
		
		row = row+adj[d].d_row;
		col = col+adj[d].d_col;
		
		visited[row][col] = true;
	}
}

void	input(void)
{
	cin>>h>>w>>s>>n;
	
	for(int row=1;row<=h;row++)
	{
		fill(&visited[row][1],&visited[row][w+1],false);
	}
	
	for(int i=1;i<=n;i++)
	{
		string	p;
		
		cin>>p;
		mark_patrol(p);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	cnt;
		
		input();
		cnt = 0;
		
		for(int row=1;row<=h;row++)
		{
			for(int col=1;col<=w;col++)
			{
				if( visited[row][col] == false )
				{
					if( s <= get_size_of_cavity(row,col) )
					{
						cnt++;
					}
				}
			}
		}
		
		cout<<"Data Set "<<k<<":\n"<<cnt<<"\n\n";
	}
	
	return	0;
}
