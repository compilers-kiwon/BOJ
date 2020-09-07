#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	NONE	-1
#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	VISITED		5
#define	NOT_VISITED	6

#define	INF			1000000

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct{int x,y;} 	RowCol;
typedef	struct{int x,y,d;}	State;

const RowCol adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N,M,map[MAX_SIZE][MAX_SIZE];

void	init_map(int y_size,int x_size,int skip_value)
{
	for(int y=0;y<=y_size;y++)
	{
		for(int x=0;x<=x_size;x++)
		{
			if( map[y][x] != skip_value )
			{
				map[y][x] = NOT_VISITED;
			}
		}
	}
}

int		find_shortest_path(RowCol s,RowCol e)
{
	queue<State>	q;
	State			tmp;
	
	tmp.x = s.x;
	tmp.y = s.y;
	q.push(tmp);
	map[s.y][s.x] = VISITED;
	
	while( !q.empty() )
	{
		int	current_x,current_y,current_d;
		
		current_x = q.front().x;
		current_y = q.front().y;
		current_d = q.front().d;
		
		q.pop();
		
		if( current_x==e.x && current_y==e.y )
		{
			int	path_len;
			
			for(path_len=0;!(current_x==s.x&&current_y==s.y);path_len++)
			{
				current_d = map[current_y][current_x];
				map[current_y][current_x] = VISITED;
				
				current_x -= adj[current_d].x;
				current_y -= adj[current_d].y;
				//cout<<"("<<current_x<<","<<current_y<<")\n";
			}
			//cout<<"=========\n";
			return	path_len;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_x,adj_y;
			
			adj_x = current_x+adj[d].x;
			adj_y = current_y+adj[d].y;
			
			if( IN_RANGE(0,adj_x,N) && IN_RANGE(0,adj_y,M) )
			{
				if( map[adj_y][adj_x] == NOT_VISITED )
				{
					map[adj_y][adj_x] = d;
					tmp.x=adj_x;tmp.y=adj_y;tmp.d=d;
					q.push(tmp);
				}
			}
		}
	}
	
	return	INF;
}

int		main(void)
{
	RowCol	A1,A2,B1,B2;
	
	cin>>N>>M>>A1.x>>A1.y>>A2.x>>A2.y>>B1.x>>B1.y>>B2.x>>B2.y;
	
	int	d1,d2;
	
	init_map(M,N,NONE);
	
	map[B1.y][B1.x] = map[B2.y][B2.x] = VISITED;
	d1 = find_shortest_path(A1,A2);
	
	init_map(M,N,VISITED);
	
	map[B1.y][B1.x] = map[B2.y][B2.x] = NOT_VISITED;
	d1 += find_shortest_path(B1,B2);
	
	init_map(M,N,NONE);
	
	map[A1.y][A1.x] = map[A2.y][A2.x] = VISITED;
	d2 = find_shortest_path(B1,B2);
	
	init_map(M,N,VISITED);
	
	map[A1.y][A1.x] = map[A2.y][A2.x] = NOT_VISITED;
	d2 += find_shortest_path(A1,A2);
	
	if( d1>=INF && d2>=INF )
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		cout<<min(d1,d2)<<'\n';
	}
	
	return	0;
}
