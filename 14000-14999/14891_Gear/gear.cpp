#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_TOOTH	8
#define	MAX_GEAR	4

#define	NORTH	'0'
#define	SOUTH	'1'

#define	CLOCKWISE			1
#define	COUNTERCLOCKWISE	-1

#define	REVERSE(d)	(((d)==CLOCKWISE)?COUNTERCLOCKWISE:CLOCKWISE)

char	gear[MAX_GEAR][MAX_TOOTH+1];

typedef	pair<int,int>	Rotate;	// first:gear_idx,second:rotate_direction

void	rotate_clockwise(char* t)
{
	char tmp;
	
	tmp = t[MAX_TOOTH-1];
	
	for(int i=MAX_TOOTH-1;i>0;i--)
	{
		t[i] = t[i-1];
	}
	
	t[0] = tmp;
}

void	rotate_counterclockwise(char* t)
{
	char	tmp;
	
	tmp = t[0];
	
	for(int i=1;i<MAX_TOOTH;i++)
	{
		t[i-1] = t[i];
	}
	
	t[MAX_TOOTH-1] = tmp;
}

void	find_gears_to_be_rotated(int g,int rotate_direction,queue<Rotate>& r)
{
	// 1. left side
	for(int i=g-1,d=REVERSE(rotate_direction);i>=0;i--,d=REVERSE(d))
	{
		char	my_teeth,opposite_teeth;
		
		my_teeth = gear[i][2];
		opposite_teeth = gear[i+1][6];
		
		if( my_teeth != opposite_teeth )
		{
			r.push(make_pair(i,d));
		}
		else
		{
			break;
		}
	}
	
	// 2.right side
	for(int i=g+1,d=REVERSE(rotate_direction);i<MAX_GEAR;i++,d=REVERSE(d))
	{
		char	my_teeth,opposite_teeth;
		
		my_teeth = gear[i][6];
		opposite_teeth = gear[i-1][2];
		
		if( my_teeth != opposite_teeth )
		{
			r.push(make_pair(i,d));
		}
		else
		{
			break;
		}
	}
}

int		get_score(void)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<MAX_GEAR;i++)
	{
		ret += (int)(gear[i][0]-'0')*(1<<i);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int i=0;i<MAX_GEAR;i++)
	{
		cin>>&gear[i][0];
	}
	
	int				K;
	
	cin>>K;
	
	for(int i=1;i<=K;i++)
	{
		int				g,d;
		queue<Rotate>	rotate_q;
		
		cin>>g>>d;
		g--;
		
		rotate_q.push(make_pair(g,d));
		find_gears_to_be_rotated(g,d,rotate_q);
		
		for(;!rotate_q.empty();)
		{
			int	current_gear,current_direction;
			
			current_gear = rotate_q.front().first;
			current_direction = rotate_q.front().second;
			
			rotate_q.pop();
			
			if( current_direction == CLOCKWISE )
			{
				rotate_clockwise(&gear[current_gear][0]);
			}
			else
			{
				rotate_counterclockwise(&gear[current_gear][0]);
			}
		}
	}
	
	cout<<get_score()<<'\n';
	
	return	0;
}
