#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_COMPUTERS	(100+1)

vector<int>		connected_computers[MAX_NUM_OF_COMPUTERS];
vector<bool>	infected(MAX_NUM_OF_COMPUTERS,false);
queue<int>		computer_queue;

int	main(void)
{
	int	num_of_computers,num_of_connections,num_of_infected_computers;
	
	cin>>num_of_computers>>num_of_connections;
	
	for(int i=1;i<=num_of_connections;i++)
	{
		int	c1,c2;
		
		cin>>c1>>c2;
		
		connected_computers[c1].push_back(c2);
		connected_computers[c2].push_back(c1);
	}
	
	num_of_infected_computers = 0;
	computer_queue.push(1);
	
	while( computer_queue.size() != 0 )
	{
		int	infected_computer;
		
		infected_computer = computer_queue.front();
		computer_queue.pop();
		
		if( infected[infected_computer] == true )
		{
			continue;
		}
		
		infected[infected_computer] = true;
		++num_of_infected_computers;
		
		for(int i=0;i<connected_computers[infected_computer].size();i++)
		{
			int	connected_computer;
			
			connected_computer = connected_computers[infected_computer][i];
			
			if( infected[connected_computer] == false )
			{
				computer_queue.push(connected_computer);
			}
		}
	}
	cout<<num_of_infected_computers-1<<endl;
	
	return	0;
}

