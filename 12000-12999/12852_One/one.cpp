#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Number; // first: current_num, second: current_num_of_operations

#define	MAX_NUM	(1000000+1)

int	find_min_op(vector<bool>& visited,vector<int>& path,int& final)
{
	Number			n;
	queue<Number>	num_q;
	int				min_op_num;
	
	n.first = 1;
	n.second = 0;
	
	num_q.push(n);
	visited[1] = true;
	path[1] = -1;
	
	while( num_q.size() != 0 )
	{
		int	current_number,current_num_of_operations;
		int	next_number,next_num_of_operations;
		
		current_number = num_q.front().first;
		current_num_of_operations = num_q.front().second;
		num_q.pop();
		
		if( current_number == final )
		{
			return	 current_num_of_operations;
		}
		
		next_num_of_operations = current_num_of_operations+1;
		
		// x3
		next_number = current_number*3;
		
		if( next_number <= final && visited[next_number] == false )
		{
			n = make_pair(next_number,next_num_of_operations);
			
			num_q.push(n);
			visited[next_number] = true;
			path[next_number] = current_number;
		}
		
		// x2
		next_number = current_number*2;
		
		if( next_number <= final && visited[next_number] == false )
		{
			n = make_pair(next_number,next_num_of_operations);
			
			num_q.push(n);
			visited[next_number] = true;
			path[next_number] = current_number;
		}
		
		// +1
		next_number = current_number+1;
		
		if( next_number <= final && visited[next_number] == false )
		{
			n = make_pair(next_number,next_num_of_operations);
			
			num_q.push(n);
			visited[next_number] = true;
			path[next_number] = current_number;
		}
	}
	return	-1;
}

int	main(void)
{
	vector<bool>	visited(MAX_NUM,false);
	vector<int>		path(MAX_NUM,-1);
	int				N,i;
	
	cin>>N;
	
	cout<<find_min_op(visited,path,N)<<endl;
	
	for(i=N;path[i]!=-1;i=path[i])
	{
		cout<<i<<" ";
	}
	cout<<i<<endl;
	
	return	0;
}
