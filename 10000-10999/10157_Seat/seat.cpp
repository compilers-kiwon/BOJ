#include	<iostream>

using namespace	std;

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	NEXT_DIR(d)	(((d)+1)%MAX_DIR)
#define	PREV_DIR(d)	(((d)+3)%MAX_DIR)

int	main(void)
{
	int	C,R,K;
	
	cin>>C>>R>>K;
	
	if( C*R < K )
	{
		cout<<"0\n";
		return	0;
	}
	
	int	x,y,d,cnt,current_dir;
	
	x = 1;
	y = 0;
	d = 0;
	cnt = 0;
	current_dir = UP;
	
	for(;cnt<K;)
	{
		if( current_dir == UP )
		{
			y += R+d;
			cnt += R+d;
			d--;
		}
		else if( current_dir == RIGHT )
		{
			x += C+d;
			cnt += C+d;
		}
		else if( current_dir == DOWN )
		{
			y -= R+d;
			cnt += R+d;
			d--;
		}
		else
		{
			x -= C+d;
			cnt += C+d;
		}
		
		current_dir = NEXT_DIR(current_dir);
	}
	
	if( cnt != K )
	{
		int	diff,prev_dir;
		
		diff = cnt-K;
		prev_dir = PREV_DIR(current_dir);
		
		if( prev_dir == UP )
		{
			y -= diff;
		}
		else if( prev_dir == RIGHT )
		{
			x -= diff;
		}
		else if( prev_dir == DOWN )
		{
			y += diff;
		}
		else
		{
			x += diff;
		}
	}
	
	cout<<x<<' '<<y<<endl;
	
	return	0;
}
