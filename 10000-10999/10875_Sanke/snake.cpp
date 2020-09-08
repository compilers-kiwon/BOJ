#include	<cstdio>
#include	<vector>

using namespace	std;

#define	VERT	1
#define	HORI	2

typedef	unsigned long long	uint64;

typedef	struct	_MOVEMENT_INFO	Movement;
struct	_MOVEMENT_INFO
{
	int	x1,y1,x2,y2;	//	x1<=x2,y1<=y2
	int	type;
};

vector<Movement>			movements;
vector< pair<int,char> >	snake;
 
#define	UP			0
#define	RIGHT		1
#define	DOWN		2
#define	LEFT		3
#define	MAX_DIR		4

#define	NEXT_DIR(cur_dir,turn_dir)	((turn_dir)=='L'?(((cur_dir)+3)%MAX_DIR):(((cur_dir)+1)%MAX_DIR))

int	L,N;

void	init_movements(void)
{
	Movement	m;
	
	// (-L-1,L+1) ~ (L+1,L+1)
	m.x1 = -L-1;m.y1 = L+1;
	m.x2 = L+1;m.y2 = L+1;
	m.type = HORI;
	movements.push_back(m);
	
	// (-L-1,-L-1) ~ (-L-1,L+1)
	m.x1 = -L-1;m.y1 = -L-1;
	m.x2 = -L-1;m.y2 = L+1;
	m.type = VERT;
	movements.push_back(m);
	
	// (-L-1,-L-1) ~ (L+1,-L-1)
	m.x1 = -L-1;m.y1 = -L-1;
	m.x2 = L+1;m.y2 = -L-1;
	m.type = HORI;
	movements.push_back(m);
	
	// (L+1,-L-1) ~ (L+1,L+1)
	m.x1 = L+1;m.y1 = -L-1;
	m.x2 = L+1;m.y2 = L+1;
	m.type = VERT;
	movements.push_back(m);
	
	// (0,0) ~ (0,0)
	m.x1 = 0;m.y1 = 0;
	m.x2 = 0;m.y2 = 0;
	m.type = HORI;
	movements.push_back(m);
}

bool	is_bumped(int from_x,int from_y,int to_x,int to_y,int type,int dir,int& min_time_to_bump)
{
	int	tmp_min;
	
	min_time_to_bump = tmp_min = 0x7FFFFFFF;
	
	for(int i=0;i<movements.size();i++)
	{
		if( type == HORI )
		{
			if( movements[i].type == HORI && from_y == movements[i].y1 )
			{
				if( dir == RIGHT && (from_x<=movements[i].x1 && movements[i].x1<=to_x) )
				{
					tmp_min = movements[i].x1-from_x;
				}
				else if( dir == LEFT && (from_x>=movements[i].x2 && movements[i].x2>=to_x) )
				{
					tmp_min = from_x-movements[i].x2;
				}
			}
			else if( movements[i].type == VERT && (movements[i].y1<=from_y && from_y<=movements[i].y2) )
			{
				if( dir == RIGHT && (from_x<=movements[i].x1 && movements[i].x1<=to_x) )
				{
					tmp_min = movements[i].x1-from_x;
				}
				else if( dir == LEFT && (from_x>=movements[i].x1 && movements[i].x1>=to_x) )
				{
					tmp_min = from_x-movements[i].x1;
				}
			}
		}
		else	// VERT
		{
			if( movements[i].type == HORI && (movements[i].x1<=from_x && from_x<=movements[i].x2) )
			{
				if( dir == UP && (from_y<=movements[i].y1 &&movements[i].y1<=to_y) )
				{
					tmp_min = movements[i].y1-from_y;
				}
				else if( dir == DOWN && (from_y>=movements[i].y1 &&movements[i].y1>=to_y) )
				{
					tmp_min = from_y-movements[i].y1;
				}
			}
			else if( movements[i].type == VERT && from_x == movements[i].x1 )
			{
				if( dir == UP && (from_y<=movements[i].y1 && movements[i].y1<=to_y) )
				{
					tmp_min = movements[i].y1-from_y;
				}
				else if( dir == DOWN && (from_y>=movements[i].y2 && to_y<=movements[i].y2) )
				{
					tmp_min = from_y-movements[i].y2;
				}
			}
		}
		
		if( tmp_min < min_time_to_bump )
		{
			//printf("bumped!!\n%d %d %d %d %d\n",i,movements[i].x1,movements[i].y1,movements[i].x2,movements[i].y2);
			min_time_to_bump = tmp_min;
		}
	}
	//printf("min_time_to_bump=%x\n",min_time_to_bump);
	if( min_time_to_bump != 0x7FFFFFFF )
	{
		return	true;
	}
	
	return	false;
}

int		main(void)
{
	scanf("%d %d",&L,&N);
	
	for(int i=0;i<N;i++)
	{
		int		t;
		char	d;
		
		scanf("%d %c",&t,&d);
		snake.push_back(make_pair(t,d));
	}
	snake.push_back(make_pair(3*L,'L'));
	
	init_movements();
	
	int		prev_x,prev_y,prev_dir;
	int		from_x,from_y,to_x,to_y;
	int		distance_to_move,type;
	int		min_time;
	bool	bump_flag;
	
	uint64	current_time;
	
	prev_x = 1;
	prev_y = 0;
	prev_dir = RIGHT;
	current_time = 1;
	
	for(int i=0;i<=N;i++)
	{
		int		t;
		char	dir;
		
		t = snake[i].first;
		dir = snake[i].second;
		
		from_x = to_x = prev_x;
		from_y = to_y = prev_y;
		distance_to_move = t-1;
		
		if( prev_dir == UP )
		{
			to_y = to_y+distance_to_move;
			type = VERT;
		}
		else if( prev_dir == RIGHT )
		{
			to_x = to_x+distance_to_move;
			type = HORI;
		}
		else if( prev_dir == DOWN )
		{
			to_y = to_y-distance_to_move;
			type = VERT;
		}
		else	// LEFT
		{
			to_x = to_x-distance_to_move;
			type = HORI;
		}
		//printf("(%d,%d)->(%d,%d)\n",from_x,from_y,to_x,to_y);
		if( (bump_flag = is_bumped(from_x,from_y,to_x,to_y,type,prev_dir,min_time)) == true )
		{
			//printf("Bump!!\n");
			current_time = current_time+(uint64)min_time;
			break;
		}
		else
		{
			Movement	m;
			
			m.x1 = min(from_x,to_x);
			m.y1 = min(from_y,to_y);
			m.x2 = max(from_x,to_x);
			m.y2 = max(from_y,to_y);
			m.type = type;
			
			movements.push_back(m);
			
			current_time = current_time+(uint64)t;
			
			prev_x = to_x;
			prev_y = to_y;
			prev_dir = NEXT_DIR(prev_dir,dir);
			
			
			if( prev_dir == UP )
			{
				++prev_y;
			}
			else if( prev_dir == DOWN )
			{
				--prev_y;
			}
			else if( prev_dir == RIGHT )
			{
				++prev_x;
			}
			else	// LEFT
			{
				--prev_x;
			}
		}
	}
	printf("%llu\n",current_time);
	
	return	0;
}


