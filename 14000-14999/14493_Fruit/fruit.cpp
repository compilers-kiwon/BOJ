#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50000+1)

int				N;
pair<int,int>	robot[MAX_SIZE];

void	go(int& current_time,int robot_index)
{
	int		p,tmp;
	int&	time_to_appear = robot[robot_index].first;
	int&	time_to_operate = robot[robot_index].second;
	
	p = time_to_operate+time_to_appear;
	tmp = current_time%p;
	
	if( tmp == 0 )
	{
		current_time += time_to_operate+1;
	}
	else
	{
		if( tmp < time_to_operate )
		{
			current_time += (time_to_operate-tmp)+1;
		}
		else
		{
			current_time += 1;
		}
	}
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>robot[i].first>>robot[i].second;
	}
	
	int	time = 0;
	
	for(int i=1;i<=N;i++)
	{
		go(time,i);
	}
	
	cout<<time<<'\n';
	
	return	0;
}
