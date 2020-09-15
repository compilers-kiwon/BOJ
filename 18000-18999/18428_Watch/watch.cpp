#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(6+1)

#define	TEACHER	'T'
#define	STUDENT	'S'
#define	EMPTY	'X'
#define	WALL	'O'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		N;
char	grid[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;	// first:row,second:col

vector<Pos>	student,teacher,empty;

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			char&	c = grid[row][col];
			Pos		p;
			
			cin>>c;
			p = make_pair(row,col);
			
			switch(c)
			{
				case	STUDENT:
					student.push_back(p);
					break;
				case	TEACHER:
					teacher.push_back(p);
					break;
				case	EMPTY:
					empty.push_back(p);
					break;
				default:
					// do nothing
					break;
			}
		}
	}
}

void	build_wall(int e)
{
	Pos&	w = empty[e];
	
	grid[w.first][w.second] = WALL;
}

void	unbuild_wall(int e)
{
	Pos&	w = empty[e];
	
	grid[w.first][w.second] = EMPTY;
}

bool	find_student(void)
{
	for(int t=0;t<teacher.size();t++)
	{
		int&	t_row = teacher[t].first;
		int&	t_col = teacher[t].second;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			for(int offset=1;;offset++)
			{
				int	adj_row,adj_col;
				
				adj_row = t_row+adj[d].d_row*offset;
				adj_col = t_col+adj[d].d_col*offset;
				
				if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
				{
					break;
				}
				
				char&	c = grid[adj_row][adj_col];
				
				if( c==TEACHER || c==WALL )
				{
					break;
				}
				
				if( c == STUDENT )
				{
					return	true;
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	input();
	
	int	num_of_empty;
	
	num_of_empty = empty.size();
	
	for(int i=0;i<num_of_empty-2;i++)
	{
		build_wall(i);
		
		for(int j=i+1;j<num_of_empty-1;j++)
		{
			build_wall(j);
			
			for(int k=j+1;k<num_of_empty;k++)
			{
				build_wall(k);
				
				if( find_student() == false )
				{
					cout<<"YES\n";
					return	0;
				}
				
				unbuild_wall(k);
			}
			
			unbuild_wall(j);
		}
		
		unbuild_wall(i);
	}
	
	cout<<"NO\n";
	
	return	0;
}
