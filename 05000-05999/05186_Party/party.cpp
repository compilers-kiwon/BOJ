#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_LOCATION	(500+1)

typedef	struct	_LOCATION_INFO	Location;
struct	_LOCATION_INFO
{
	int	num_of_drunken;
	int	num_of_normal;
	priority_queue<int>	car;
};

#define	DRUNKEN	'I'
#define	NORMAL	'S'

void	input(int& num_of_locations,Location* l)
{
	int	num_of_friends,num_of_cars;
	
	cin>>num_of_friends>>num_of_cars>>num_of_locations;
	
	for(int i=1;i<=num_of_locations;i++)
	{
		l[i].num_of_drunken = l[i].num_of_normal = 0;
		for(;!l[i].car.empty();l[i].car.pop());
	}
	
	for(int i=1;i<=num_of_friends;i++)
	{
		int		where_to_go;
		char	state;
		
		cin>>where_to_go>>state;
		
		if( state == DRUNKEN )
		{
			l[where_to_go].num_of_drunken++;
		}
		else
		{
			l[where_to_go].num_of_normal++;
		}
	}
	
	for(int i=1;i<=num_of_cars;i++)
	{
		int	where_to_go,capacity;
		
		cin>>where_to_go>>capacity;
		l[where_to_go].car.push(capacity);
	}
}

int		get_num_of_lefts(Location& l)
{
	int	ret,num_of_drivers;
	
	ret = l.num_of_drunken+l.num_of_normal;
	num_of_drivers = min((int)l.car.size(),l.num_of_normal);
	
	for(;num_of_drivers>0&&!l.car.empty()&&ret>0;num_of_drivers--)
	{
		int	current_car_capacity;
		
		current_car_capacity = l.car.top();
		l.car.pop();
		
		ret = max(0,ret-current_car_capacity);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int			num_of_locations,num_of_lefts;
		Location	locations[MAX_LOCATION];
		
		num_of_lefts = 0;
		input(num_of_locations,locations);
		
		for(int i=1;i<=num_of_locations;i++)
		{
			num_of_lefts += get_num_of_lefts(locations[i]);
		}
		
		cout<<"Data Set "<<k<<":\n"<<num_of_lefts<<'\n';
	}
	
	return	0;
}
