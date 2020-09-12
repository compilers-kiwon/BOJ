#include	<iostream>
#include	<string>

using namespace	std;

#define	LEFT	0
#define	RIGHT	1

#define	NORTH	0
#define	EAST	1
#define	SOUTH	2
#define	WEST	3
#define	MAX_DIR	4

#define	TURN_LEFT(d)	(((d)+MAX_DIR-1)%MAX_DIR)
#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const struct{
	int	d_row,d_col;
}move_dir[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

bool	move_robot(int size,int& current_row,int& current_col,int& current_dir,int num_of_command)
{
	if( IN_RANGE(0,current_row,size) == false || IN_RANGE(0,current_col,size) == false )
	{
		return	false;
	}
	
	if( num_of_command == 0 )
	{
		return	true;
	}
	
	string	command;
	int		parameter;
	
	cin>>command>>parameter;
	
	if( command == "MOVE" )
	{
		current_row = current_row+move_dir[current_dir].d_row*parameter;
		current_col = current_col+move_dir[current_dir].d_col*parameter;
	}
	else
	{
		if( parameter == LEFT )
		{
			current_dir = TURN_LEFT(current_dir);
		}
		else
		{
			current_dir = TURN_RIGHT(current_dir);
		}
	}
	
	return	move_robot(size,current_row,current_col,current_dir,num_of_command-1);
}

int		main(void)
{
	int	M,n,row,col,direction;
	
	cin>>M>>n;
	row = col = 0;
	direction = EAST;
	
	if( move_robot(M,row,col,direction,n) == true )
	{
		cout<<col<<' '<<row<<endl;
	}
	else
	{
		cout<<"-1\n";
	}
	
	return	0;
}
