#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_COLLEAGUE	50

int	find_max_time(int colleague,vector<int>* my_managee)
{
	int					time,i;
	priority_queue<int>	time_q;
	
	for(i=0;i<my_managee[colleague].size();i++)
	{
		time_q.push(find_max_time(my_managee[colleague][i],my_managee));
	}
	
	for(time=0,i=1;time_q.size()!=0;i++)
	{
		time = max(time,time_q.top()+i);
		time_q.pop();
	}
	return	time;
}

int	main(void)
{
	int			N;
	vector<int>	my_managee[MAX_NUM_OF_COLLEAGUE];
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		int	m;
		
		cin>>m;
		
		if( m >= 0 )
		{
			my_managee[m].push_back(i);
		}
	}
	
	cout<<find_max_time(0,my_managee)<<endl;
	
	return	0;
}
