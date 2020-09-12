#include	<iostream>
#include	<vector>
#include	<queue>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_CIRCLE	(1000+1)

#define	NONE			-1
#define	COLOR_1			0
#define	COLOR_2			1
#define	MAX_COLOR		2
#define	NEXT_COLOR(c)	(((c)+1)%MAX_COLOR)

void	input(vector<int>* connected,int& num_of_circle,int& num_of_line)
{
	cin>>num_of_circle>>num_of_line;
	
	for(int i=1;i<=num_of_line;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		connected[x].push_back(y);
		connected[y].push_back(x);
	}
}

bool	fill_circle(int start_circle,vector<int>* connected,vector<int>& circle_color)
{
	queue<int>	circle_queue;
	bool		result;
	
	circle_queue.push(start_circle);
	circle_color[start_circle] = COLOR_1;
	result = true;
	
	while( !circle_queue.empty() && result == true )
	{
		int	current_circle,current_color,next_color;
		
		current_circle = circle_queue.front();
		current_color = circle_color[current_circle];
		next_color = NEXT_COLOR(current_color);
		
		circle_queue.pop();
		
		vector<int>& connected_circles = connected[current_circle];
		
		for(int i=0;i<connected_circles.size();i++)
		{
			int&	connected_circle = connected_circles[i];
			
			if( circle_color[connected_circle] == NONE )
			{
				circle_color[connected_circle] = next_color;
				circle_queue.push(connected_circle);
			}
			else
			{
				if( circle_color[connected_circle] != next_color )
				{
					result = false;
					break;
				}
			}	
		}	
	}
	
	return	result;
}

bool	is_possible_to_fill_circle(vector<int>* connected,int& num_of_circle)
{
	vector<int>	circle(num_of_circle+1,NONE);
	int			i;
	bool		result;
	
	for(i=1,result=true;i<=num_of_circle;i++)
	{
		if( circle[i] != NONE )
		{
			continue;
		}
		
		if( fill_circle(i,connected,circle) == false )
		{
			result = false;
			break;
		}
	}
	return	result;
}

int		main(void)
{
	string	str;
	
	cin>>str;
	cout<<str.length();
	return	0;
	
	/*
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int			n,m;
		vector<int>	connected[MAX_NUM_OF_CIRCLE];
		
		input(connected,n,m);
		
		if( is_possible_to_fill_circle(connected,n) == true )
		{
			cout<<"possible\n";
		}
		else
		{
			cout<<"impossible\n";
		}
		
		T--;
	}
	*/
	return	0;
}
