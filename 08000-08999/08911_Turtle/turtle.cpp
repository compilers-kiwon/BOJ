#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	TURN_LEFT(d)	(((d)+MAX_DIR-1)%MAX_DIR)
#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)

#define	GET_BACKWARD(d)	(((d)+2)%MAX_DIR)

const struct{
	int dx,dy;
} adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

int		min_x,max_x,min_y,max_y;

void	move_turtle(int x,int y,int dir,string& op,int index)
{
	int	next_x,next_y;
	
	if( index == op.length() )
	{
		return;
	}
	
	switch(op[index])
	{
		case	'F':
			x += adj[dir].dx;
			y += adj[dir].dy;
			break;
		case	'B':
			x += adj[GET_BACKWARD(dir)].dx;
			y += adj[GET_BACKWARD(dir)].dy;
			break;
		case	'L':
			dir = TURN_LEFT(dir);
			break;
		case	'R':
			dir = TURN_RIGHT(dir);
			break;
		default:
			// do nothing
			break;
	}
	
	min_x = min(min_x,x);
	max_x = max(max_x,x);
	max_y = max(max_y,y);
	min_y = min(min_y,y);
	
	move_turtle(x,y,dir,op,index+1);
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	t;
		
		cin>>t;
		
		min_x = max_x = max_y = min_y = 0;
		
		move_turtle(0,0,NORTH,t,0);
		
		cout<<abs(max_x-min_x)*abs(max_y-min_y)<<endl;
		
		T--;
	}
	
	return	0;
}
