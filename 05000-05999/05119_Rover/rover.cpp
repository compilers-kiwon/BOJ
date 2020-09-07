#include	<iostream>
#include	<string>

using namespace	std;

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)
#define	TURN_LEFT(d)	(((d)+MAX_DIR-1)%MAX_DIR)

#define	is_stopped(s)	((s)==0)
#define	is_forward(s)	((s)>=1)

#define	MAX_SPEED	5

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int		n,x,y,d,speed;
		string	command;
		
		x = y = speed = 0;
		d = UP;
		
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			string	command;
			
			cin>>command;
			
			if( command=="FORWARD" && is_stopped(speed)==true )
			{
				speed = 1;
			}
			else if( command=="BACKWARD" && is_stopped(speed)==true )
			{
				speed = -1;
			}
			else if( command=="FASTER" && is_forward(speed)==true )
			{
				speed = min(speed+1,MAX_SPEED);
			}
			else if( command=="SLOWER" && is_forward(speed)==true )
			{
				speed = max(speed-1,0);
			}
			else if( command=="STOP" && is_stopped(speed)==false )
			{
				speed = 0;
			}
			else if( command=="RIGHT" && is_stopped(speed)==true )
			{
				d = TURN_RIGHT(d);
			}
			else if( command=="LEFT" && is_stopped(speed)==true )
			{
				d = TURN_LEFT(d);
			}
			
			x = x+adj[d].dx*speed;
			y = y+adj[d].dy*speed;
		}
		
		cout<<"Data Set "<<k<<":\n"<<x<<' '<<y<<"\n\n";
	}
	
	return	0;	
}
