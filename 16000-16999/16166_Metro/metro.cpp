#include	<iostream>
#include	<map>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_LINE		(10+1)
#define	SEOUL_STATION		0

typedef	vector<int>		Line;
typedef	unsigned int	uint32;
typedef	pair<int,int>	State;

vector<uint32>		stations[MAX_NUM_OF_LINE];
map<uint32,Line>	metro_line;
vector<int>			connected[MAX_NUM_OF_LINE];

bool	find_station(int line_no,uint32 station)
{
	vector<uint32>&	s = stations[line_no];
	
	for(int i=0;i<s.size();i++)
	{
		if( s[i] == station )
		{
			return	true;
		}
	}
	
	return	false;
}

void	init(int& num_of_lines,uint32& destination)
{
	cin.sync_with_stdio(false);
	
	cin>>num_of_lines;
	
	for(int i=1;i<=num_of_lines;i++)
	{
		int	K;
		
		cin>>K;
		
		for(int j=1;j<=K;j++)
		{
			uint32	s;
			
			cin>>s;
			
			if( stations[i].empty() || s!=stations[i][0] )
			{
				stations[i].push_back(s);
				metro_line[s].push_back(i);
			}
		}
	}
	
	map<uint32,Line>::iterator	it;
	
	for(it=metro_line.begin();it!=metro_line.end();it++)
	{
		Line&	connected_lines = it->second;
		
		for(int i=0;i<connected_lines.size()-1;i++)
		{
			int&	l1 = connected_lines[i];
			
			for(int j=i+1;j<connected_lines.size();j++)
			{
				int&	l2 = connected_lines[j];
				
				connected[l1].push_back(l2);
				connected[l2].push_back(l1);
			}
		}
		
	}
	
	cin>>destination;
}

int		find_min_num_of_transfer(int num_of_lines,uint32 destination)
{
	vector<int>				dp(num_of_lines+1,0x7FFFFFFF);
	priority_queue<State>	line_q;
	
	vector<int>&	start_line = metro_line[SEOUL_STATION];
	
	for(int i=0;i<start_line.size();i++)
	{
		line_q.push(make_pair(0,start_line[i]));
	}
	
	while( !line_q.empty() )
	{
		int	current_num_of_transfer,current_line;
		
		current_num_of_transfer = -line_q.top().first;
		current_line = line_q.top().second;
		line_q.pop();
		
		if( find_station(current_line,destination) == true )
		{
			return	current_num_of_transfer;
		}
		
		vector<int>&	adj_lines = connected[current_line];
		int				next_num_of_transfer = current_num_of_transfer+1;
		
		for(int i=0;i<adj_lines.size();i++)
		{
			int&	adj_line = adj_lines[i];
			
			if( next_num_of_transfer < dp[adj_line] )
			{
				dp[adj_line] = next_num_of_transfer;
				line_q.push(make_pair(-next_num_of_transfer,adj_line));
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	int		N;
	uint32	D;
	
	init(N,D);
	cout<<find_min_num_of_transfer(N,D)<<'\n';
	
	return	0;
}
