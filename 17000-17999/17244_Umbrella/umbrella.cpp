#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	MAX_THINGS	(5+1)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N,M,num_of_things;
int		distance_from_start_to_things[MAX_THINGS];
int		distance_between_things[MAX_THINGS][MAX_THINGS];
int		distance_from_things_to_end[MAX_THINGS];
char	map[MAX_SIZE][MAX_SIZE+1];

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<Pos,int>	State;	// first:Pos,second:distance

Pos			start_pos,end_pos,things[MAX_THINGS];

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=M;row++)
	{
		scanf("%s",&map[row][1]);
		
		for(int col=1;col<=N;col++)
		{
			switch(map[row][col])
			{
				case	'S':
					start_pos = make_pair(row,col);
					map[row][col] = '.';
					break;
				case	'X':
					num_of_things++;
					things[num_of_things] = make_pair(row,col);
					map[row][col] = '.';
					break;
				case	'E':
					end_pos = make_pair(row,col);
					map[row][col] = '.';
					break;
				default :
					// do nothing
					break;
			}
		}
	}
}

int		get_distance(Pos& p1,Pos& p2)
{
	bool			visited[MAX_SIZE][MAX_SIZE];
	int				ret;
	queue<State>	state_q;
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			visited[row][col] = false;
		}
	}
	
	visited[p1.first][p1.second] = true;
	state_q.push(make_pair(p1,0));
	
	for(;!state_q.empty();)
	{
		int	current_row,current_col,current_distance;
		
		current_row = state_q.front().first.first;
		current_col = state_q.front().first.second;
		current_distance = state_q.front().second;
		
		state_q.pop();
		
		if( current_row==p2.first && current_col==p2.second )
		{
			ret = current_distance;
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col,adj_distance;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			adj_distance = current_distance+1;
			
			if( IN_RANGE(1,adj_row,M) && IN_RANGE(1,adj_col,N) 
				&& map[adj_row][adj_col]=='.' && visited[adj_row][adj_col]==false )
			{
				visited[adj_row][adj_col] = true;
				state_q.push(make_pair(make_pair(adj_row,adj_col),adj_distance));
			}
		}
	}
	
	return	ret;
}

void	dfs(int current_num_of_visited_things,vector<int>& visited_order,
			vector<bool>& visited,int& min_distance)
{
	if( current_num_of_visited_things == num_of_things )
	{
		int	current_distance;
		
		current_distance = distance_from_start_to_things[visited_order[0]];
		
		for(int i=1;i<num_of_things;i++)
		{
			current_distance += distance_between_things[visited_order[i-1]][visited_order[i]];
		}
		
		current_distance += distance_from_things_to_end[visited_order.back()];
		
		min_distance = min(min_distance,current_distance);
		
		return;
	}
	
	for(int i=1;i<=num_of_things;i++)
	{
		if( visited[i] == false )
		{
			visited[i] = true;
			visited_order.push_back(i);
			
			dfs(current_num_of_visited_things+1,visited_order,visited,min_distance);
			
			visited_order.pop_back();
			visited[i] = false;
		}
	}
}

int		main(void)
{
	input();
	
	if( num_of_things == 0 )
	{
		printf("%d\n",get_distance(start_pos,end_pos));
		return	0;
	}
	
	for(int i=1;i<=num_of_things;i++)
	{
		distance_from_start_to_things[i] = get_distance(start_pos,things[i]);
	}
	
	for(int i=1;i<num_of_things;i++)
	{
		for(int j=i+1;j<=num_of_things;j++)
		{
			distance_between_things[i][j] 
			= distance_between_things[j][i] 
			= get_distance(things[i],things[j]);
		}
	}
	
	for(int i=1;i<=num_of_things;i++)
	{
		distance_from_things_to_end[i] = get_distance(things[i],end_pos);
	}
	
	vector<int>		visited_order;
	vector<bool>	visited(num_of_things+1,false);
	int				min_distance;
	
	min_distance = 0x7FFFFFFF;
	dfs(0,visited_order,visited,min_distance);
	
	printf("%d\n",min_distance);
	
	return	0;
}
