#include	<stdio.h>

#define	MAX_NUM_OF_ROBOTS	(100+1)
#define	MAX_SIZE			(100+1)

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	TURN_RIGHT(current_dir,m)	(((current_dir)+((m)%MAX_DIR))%MAX_DIR)
#define	TURN_LEFT(current_dir,m)	TURN_RIGHT(current_dir,(m)*3)

#define	EMPTY		0

#define	OK			0
#define	CRASH_WALL	1
#define	CRASH_ROBOT	2

typedef	struct	_ROBOT_INFO	Robot;
struct	_ROBOT_INFO
{
	int	dir,row,col;
};

struct{
	int	row,col;
} move_factor[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

int		map[MAX_SIZE][MAX_SIZE];
Robot	robot[MAX_NUM_OF_ROBOTS];
int		A,B,N,M;

int		move_robot(int robot_no,int movements)
{
	int	current_dir,current_row,current_col;
	int	next_row,next_col;
	int	move_factor_row,move_factor_col;
	int	i,result;
	
	current_dir = robot[robot_no].dir;
	current_row = robot[robot_no].row;
	current_col = robot[robot_no].col;
	
	next_row = current_row;
	next_col = current_col;
	
	move_factor_row = move_factor[current_dir].row;
	move_factor_col = move_factor[current_dir].col;
	
	for(result=OK,i=1;i<=movements;i++)
	{
		next_row = next_row+move_factor_row;
		next_col = next_col+move_factor_col;
		
		if( next_row<1 || next_row>B || next_col<1 || next_col>A )
		{
			result = CRASH_WALL;
			break;
		}
		
		if( map[next_row][next_col] != EMPTY )
		{
			result = CRASH_ROBOT;
			robot[robot_no].row = next_row;
			robot[robot_no].col = next_col;
			break;
		}
	}
	
	if( result == OK )
	{
		map[next_row][next_col] = robot_no;
		map[current_row][current_col] = EMPTY;
		
		robot[robot_no].row = next_row;
		robot[robot_no].col = next_col;
	}
	
	return	result;
}

int	main(void)
{
	int	i;
	
	scanf("%d %d %d %d",&A,&B,&N,&M);
	
	for(i=1;i<=N;i++)
	{
		int		x,y,dir;
		char	d;
		
		scanf("%d %d %c",&x,&y,&d);
		
		switch(d)
		{
			case	'N':
				dir = NORTH;
				break;
			case	'E':
				dir = EAST;
				break;
			case	'S':
				dir = SOUTH;
				break;
			case	'W':
				dir = WEST;
				break;
			default:
				puts("Wrong direction input!!");
				break;
		}
		
		robot[i].dir = dir;
		robot[i].row = y;
		robot[i].col = x;
		map[y][x] = i;
	}
	
	for(i=1;i<=M;i++)
	{
		int		robot_no,movements,result;
		char	instruction;
		
		scanf("%d %c %d",&robot_no,&instruction,&movements);
		
		switch(instruction)
		{
			case	'L':
				robot[robot_no].dir = TURN_LEFT(robot[robot_no].dir,movements);
				break;
			case	'R':
				robot[robot_no].dir = TURN_RIGHT(robot[robot_no].dir,movements);
				break;
			case	'F':
				result = move_robot(robot_no,movements);
				
				if( result == CRASH_WALL )
				{
					printf("Robot %d crashes into the wall\n",robot_no);
					return	0;
				}
				
				if( result == CRASH_ROBOT )
				{
					int	crashed_row,crashed_col;
					
					crashed_row = robot[robot_no].row;
					crashed_col = robot[robot_no].col;
					
					printf("Robot %d crashes into robot %d\n",robot_no,map[crashed_row][crashed_col]);
					
					return	0;
				}
				break;
			default:
				puts("Wrong instruction input!!");
				break;
		}
	}
	printf("OK\n");
	return	0;
}

