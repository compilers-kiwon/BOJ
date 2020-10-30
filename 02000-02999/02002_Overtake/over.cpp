#include	<iostream>
#include	<string>
#include	<map>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CARS	(1000+1)

void	enter(int& num_of_cars,queue<string>& car_q)
{
	cin>>num_of_cars;
	
	for(int i=1;i<=num_of_cars;i++)
	{
		string	s;
		
		cin>>s;
		car_q.push(s);
	}
}

int		pass_through_tunnel(const int& num_of_cars,queue<string>& car_q)
{
	int					ret;
	map<string,bool>	passed;
	
	ret = 0;
	
	for(int i=1;i<=num_of_cars;i++)
	{
		string	s;
		
		cin>>s;
		passed[s] = true;
		
		if( s == car_q.front() )
		{
			do{
				car_q.pop();
			}while( !car_q.empty() && passed[car_q.front()]==true );
		}
		else
		{
			ret++;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	queue<string>	car_q;
	
	enter(N,car_q);
	cout<<pass_through_tunnel(N,car_q)<<'\n';
	
	return	0;
}
