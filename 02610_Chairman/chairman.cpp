#include	<iostream>
#include	<queue>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE		(100+1)
#define	MAX_NUM_OF_COMMITTEE	(100+1)

#define	NONE	0

int			N,M,num_of_committee;
int			my_committee[MAX_NUM_OF_PEOPLE];
int			voice_distance[MAX_NUM_OF_PEOPLE][MAX_NUM_OF_PEOPLE];
int			chairman[MAX_NUM_OF_COMMITTEE];
vector<int>	connected[MAX_NUM_OF_PEOPLE];
vector<int>	committee[MAX_NUM_OF_COMMITTEE];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		connected[A].push_back(B);
		connected[B].push_back(A);
		
		voice_distance[A][B] = voice_distance[B][A] = 1;
	}
}

void	bfs(int start_member)
{
	queue<int>	committee_q;
	
	my_committee[start_member] = num_of_committee;
	committee_q.push(start_member);
	committee[num_of_committee].push_back(start_member);
	
	while( !committee_q.empty() )
	{
		int	m;
		
		m = committee_q.front();
		committee_q.pop();
		
		vector<int>&	adj = connected[m];
		
		for(int i=0;i<adj.size();i++)
		{
			int& adj_member = adj[i];
			
			if( my_committee[adj_member] == NONE )
			{
				my_committee[adj_member] = num_of_committee;
				committee_q.push(adj_member);
				committee[num_of_committee].push_back(adj_member);
			}
		}
	}
}

void	find_committee_members(void)
{
	for(int i=1;i<=N;i++)
	{
		if( my_committee[i] == NONE )
		{
			num_of_committee++;
			bfs(i);
		}
	}
}

void	update_voice_distance(void)
{
	for(int i=1;i<=num_of_committee;i++)
	{
		vector<int>&	c = committee[i];
		
		for(int k=0;k<c.size();k++)
		{
			for(int n=0;n<c.size();n++)
			{
				for(int m=0;m<c.size();m++)
				{
					int&	mid = c[k];
					int&	from = c[n];
					int&	to = c[m];
					
					if( from == to )
					{
						continue;
					}
					
					if( voice_distance[from][mid]!=NONE && voice_distance[mid][to]!=NONE )
					{
						int	d = voice_distance[from][mid]+voice_distance[mid][to];
						
						if( voice_distance[from][to]==NONE || d<voice_distance[from][to] )
						{
							voice_distance[from][to] = voice_distance[to][from] = d;
						}
					}
				}
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	find_committee_members();
	update_voice_distance();
	
	for(int k=1;k<=num_of_committee;k++)
	{
		vector<int>&	c = committee[k];
		
		int	candidate,min_voice_distance;
		
		min_voice_distance = MAX_NUM_OF_PEOPLE;
		
		for(int i=0;i<c.size();i++)
		{
			int	my_max_voice_distance;
			
			my_max_voice_distance = 0;
			
			for(int j=0;j<c.size();j++)
			{
				int&	d = voice_distance[c[i]][c[j]];
				
				my_max_voice_distance = max(my_max_voice_distance,d);
			}
			
			if( my_max_voice_distance < min_voice_distance )
			{
				min_voice_distance = my_max_voice_distance;
				candidate = c[i];
			}
		}
		
		chairman[k] = candidate;
	}
	
	sort(&chairman[1],&chairman[num_of_committee+1]);
	
	cout<<num_of_committee<<'\n';
	
	for(int i=1;i<=num_of_committee;i++)
	{
		cout<<chairman[i]<<'\n';
	}
	
	return	0;
}
