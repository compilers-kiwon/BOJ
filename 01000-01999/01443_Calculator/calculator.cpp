#include	<iostream>
#include	<vector>
#include	<queue>
#include	<cmath>
#include	<map>

using namespace	std;

#define	MAX_NUM			100000000
#define	get_index(n,v)	((n)*MAX_NUM+(v))

typedef	pair<int,int>	State;	// first:n,second:v

int				D,P,limit;
map<int,bool>	visited;

int	get_max_num(void)
{
	queue<State>	state_q;
	int				ret;
	
	for(state_q.push(make_pair(0,1)),ret=-1;!state_q.empty();)
	{
		int	current_num_of_operations,current_value;
		
		current_num_of_operations = state_q.front().first;
		current_value = state_q.front().second;
		
		state_q.pop();
		
		if( current_num_of_operations == P )
		{
			ret = max(ret,current_value);
			continue;
		}
		
		for(int n=2;n<=9;n++)
		{
			int	adj;
			
			adj = current_value*n;
			
			if( adj<limit && visited[get_index(current_num_of_operations+1,adj)]==false )
			{
				visited[get_index(current_num_of_operations+1,adj)] = true;
				state_q.push(make_pair(current_num_of_operations+1,adj));
			}
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin>>D>>P;
	limit = pow(10,D);
	
	cout<<get_max_num()<<'\n';
	
	return	0;
}
