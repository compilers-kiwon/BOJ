#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	EAST	1
#define	WEST	2
#define	SOUTH	3
#define	NORTH	4

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	TURN_LEFT(d)	(((d)+3)%MAX_DIR)
#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)

#define	IN_RANGE(MIN,N,MAX)	((MIN)<=(N)&&(N)<=(MAX))

#define	AVAILABLE	0
#define	UNAVAILABLE	1

#define	MOVE_DISTANCE	3

int		factory[MAX_SIZE][MAX_SIZE][MAX_DIR];

typedef	struct	_ROBOT_STATE	Robot;
struct	_ROBOT_STATE
{
	int	row,col,direction,num_of_movement;
};

int		convert_dir(int d)
{
	int	converted;
	
	switch(d)
	{
		case	EAST:
			converted = RIGHT;
			break;
		case	WEST:
			converted = LEFT;
			break;
		case	NORTH:
			converted = UP;
			break;
		case	SOUTH:
			converted = DOWN;
			break;
		default:
			// do nothing
			break;
	}
	
	return	converted;
}

void	move_robot(Robot& init,Robot& final,int row_size,int col_size)
{
	queue<Robot>	robot_q;
	
	robot_q.push(init);
	factory[init.row][init.col][init.direction] = init.num_of_movement;
	
	while( !robot_q.empty() )
	{
		int	current_row,current_col,current_direction,current_num_of_movement;
		
		current_row = robot_q.front().row;
		current_col = robot_q.front().col;
		current_direction = robot_q.front().direction;
		current_num_of_movement = robot_q.front().num_of_movement;
		
		robot_q.pop();
		
		if( current_row==final.row && current_col==final.col && current_direction==final.direction )
		{
			continue;
		}
		
		// GO k
		Robot	r;
		
		r.direction = current_direction;
		r.num_of_movement = current_num_of_movement+1;
		
		for(int i=1;i<=MOVE_DISTANCE;i++)
		{
			if( current_direction==UP || current_direction==DOWN )
			{
				r.col = current_col;
				
				if( current_direction == UP )
				{
					r.row = current_row-i;
				}
				else
				{
					r.row = current_row+i;
				}
			}
			else
			{
				r.row = current_row;
				
				if( current_direction == LEFT )
				{
					r.col = current_col-i;
				}
				else
				{
					r.col = current_col+i;
				}
			}
			
			if( IN_RANGE(1,r.row,row_size) && IN_RANGE(1,r.col,col_size) )
			{
				if( factory[r.row][r.col][r.direction] == -1 )
				{
					break;
				}
				else
				{
					if( r.num_of_movement < factory[r.row][r.col][r.direction] )
					{
						robot_q.push(r);
						factory[r.row][r.col][r.direction] = r.num_of_movement;
						//printf("%d %d %d %d\n",r.row,r.col,r.direction,r.num_of_movement);
					}
				}
			}
		}
		
		r.row = current_row;
		r.col = current_col;
		
		// Turn Left
		r.direction = TURN_LEFT(current_direction);
		
		if( r.num_of_movement < factory[r.row][r.col][r.direction] )
		{
			robot_q.push(r);
			factory[r.row][r.col][r.direction] = r.num_of_movement;
			//printf("%d %d %d %d\n",r.row,r.col,r.direction,r.num_of_movement);
		}
		
		// Turn Right
		r.direction = TURN_RIGHT(current_direction);
		
		if( r.num_of_movement < factory[r.row][r.col][r.direction] )
		{
			robot_q.push(r);
			factory[r.row][r.col][r.direction] = r.num_of_movement;
			//printf("%d %d %d %d\n",r.row,r.col,r.direction,r.num_of_movement);
		}
	}
}

int		main(void)
{
	int		M,N;
	Robot	init,final;
	
	cin.sync_with_stdio(false);
	
	cin>>M>>N;
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			int	state,init_value;
			
			cin>>state;
			
			if( state == AVAILABLE )
			{
				init_value = 0x7FFFFFFF;
			}
			else
			{
				init_value = -1;
			}
			
			factory[row][col][UP] = factory[row][col][DOWN] = factory[row][col][LEFT] = factory[row][col][RIGHT] = init_value;
		}
	}
	
	cin>>init.row>>init.col>>init.direction;
	init.direction = convert_dir(init.direction);
	
	cin>>final.row>>final.col>>final.direction;
	final.direction = convert_dir(final.direction);
	
	init.num_of_movement = 0;
	
	move_robot(init,final,M,N);
	
	cout<<factory[final.row][final.col][final.direction]<<'\n';
	
	return	0;
}
