#include	<iostream>
#include	<map>
#include	<string>
#include	<vector>

using namespace	std;

#define	INCONSISTENT	-1

typedef	struct	_CAR_INFO	Car;
struct	_CAR_INFO
{
	int	p,q,k;
};

typedef	struct	_EVENT_INFO	Event;
struct	_EVENT_INFO
{
	int		t;
	char	e;
	string	S,data;
};

void	input(map<string,Car>& c,vector<Event>& e)
{
	int	n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		string	name;
		Car		car;
		
		cin>>name>>car.p>>car.q>>car.k;
		c[name] = car;
	}
	
	for(int i=1;i<=m;i++)
	{
		Event event;
		
		cin>>event.t>>event.S>>event.e>>event.data;
		e.push_back(event);
	}
}

int		str2int(string& str)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+(int)(str[i]-'0');
	}
	
	return	ret;
}

int		get_accdent_cost(int loss,int price)
{
	return	((price*loss)+99)/100;
}

void	verify_log(map<string,Car>& c,vector<Event>& e)
{
	map<string,int>		cost_table,time_table;
	map<string,string>	rental_car_table;
	
	for(int i=0;i<e.size();i++)
	{
		Event&	current = e[i];
		
		if( cost_table[current.S] == INCONSISTENT )
		{
			continue;
		}
		
		switch(current.e)
		{
			case	'p':
				if( rental_car_table[current.S] != "" )
				{
					cost_table[current.S] = INCONSISTENT;
				}
				else
				{
					rental_car_table[current.S] = current.data;
					cost_table[current.S] += c[current.data].q;
					time_table[current.S] = current.t;
					//cout<<current.S<<"=>"<<cost_table[current.S]<<'\n';
				}
				break;
			case	'r':
				if( rental_car_table[current.S]=="" || current.t<time_table[current.S] )
				{
					cost_table[current.S] = INCONSISTENT;
				}
				else
				{
					string&	my_car = rental_car_table[current.S];
					
					cost_table[current.S] += str2int(current.data)*c[my_car].k;
					//cout<<current.S<<"<="<<cost_table[current.S]<<'\n';
					time_table[current.S] = 0;
					my_car = "";
				}
				break;
			case	'a':
				if( rental_car_table[current.S]=="" || current.t<time_table[current.S] )
				{
					cost_table[current.S] = INCONSISTENT;
				}
				else
				{
					string&	my_car = rental_car_table[current.S];
					
					cost_table[current.S] += get_accdent_cost(str2int(current.data),c[my_car].p);
					//cout<<current.S<<"XX"<<cost_table[current.S]<<'\n';
				}
				break;
			default:
				// do nothing
				break;
		}
	}
	
	map<string,string>::iterator	it1;
	
	for(it1=rental_car_table.begin();it1!=rental_car_table.end();it1++)
	{
		if( it1->second != "" )
		{
			cost_table[it1->first] = INCONSISTENT;
		}
	}
	
	map<string,int>::iterator	it2;
	
	for(it2=cost_table.begin();it2!=cost_table.end();it2++)
	{
		if( it2->second == INCONSISTENT )
		{
			cout<<it2->first<<" INCONSISTENT\n";
		}
		else
		{
			cout<<it2->first<<' '<<it2->second<<'\n';
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		map<string,Car>	car_table;
		vector<Event>	log;
	
		input(car_table,log);
		verify_log(car_table,log);
	}
	
	return	0;
}
