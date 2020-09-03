#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	EMPTY	'.'
#define	FIRE	'*'
#define	WALL	'#'
#define	PERSON	'@'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,N,MAX)	((MIN)<=(N)&&(N)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

char	building[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	row,col,cnt;
};

void	init(int* w,int* h,queue<State>& person,queue<State>& fire)
{
	scanf("%d %d",w,h);
	
	for(int row=1;row<=*h;row++)
	{
		scanf("%s",&building[row][1]);
		
		for(int col=1;col<=*w;col++)
		{
			visited[row][col] = false;
			
			if( building[row][col] == PERSON )
			{
				State p;
				
				p.row = row;
				p.col = col;
				p.cnt = 0;
				
				person.push(p);
				building[row][col] = EMPTY;
				visited[row][col] = true;
			}
			else if( building[row][col] == FIRE )
			{
				State f;
				
				f.row = row;
				f.col = col;
				
				fire.push(f);
			}
		}
	}
}

int		find_min_escape_time(int w,int h,queue<State>& person,queue<State>& fire)
{
	while( !person.empty() )
	{
		for(int i=1,num_of_fire=fire.size();i<=num_of_fire;i++)
		{
			int	current_row,current_col;
			
			current_row = fire.front().row;
			current_col = fire.front().col;
			
			fire.pop();
			
			for(int j=UP;j<=RIGHT;j++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[j].d_row;
				adj_col = current_col+adj[j].d_col;
				
				if( IN_RANGE(1,adj_row,h) && IN_RANGE(1,adj_col,w) && building[adj_row][adj_col] == EMPTY )
				{
					State	f;
					
					building[adj_row][adj_col] = FIRE;
					
					f.row = adj_row;
					f.col = adj_col;
					
					fire.push(f);
				}
			}
		}
		
		for(int i=1,num_of_person=person.size();i<=num_of_person;i++)
		{
			int	current_row,current_col,current_cnt;
			
			current_row = person.front().row;
			current_col = person.front().col;
			current_cnt = person.front().cnt;
			
			person.pop();
			
			for(int j=UP;j<=RIGHT;j++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[j].d_row;
				adj_col = current_col+adj[j].d_col;
				
				if( !IN_RANGE(1,adj_row,h) || !IN_RANGE(1,adj_col,w) )
				{
					return	current_cnt+1;
				}
				else
				{
					if( building[adj_row][adj_col] == EMPTY && visited[adj_row][adj_col] == false )
					{
						State	p;
						
						visited[adj_row][adj_col] = true;
						
						p.row = adj_row;
						p.col = adj_col;
						p.cnt = current_cnt+1;
						
						person.push(p);
					}
				}
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	w,h,escape;
		
		queue<State>	person;
		queue<State>	fire;
		
		init(&w,&h,person,fire);
		
		escape = find_min_escape_time(w,h,person,fire);
		
		if( escape == -1 )
		{
			puts("IMPOSSIBLE");
		}
		else
		{
			printf("%d\n",escape);
		}
		
		T--;
	}
	
	return	0;
}
