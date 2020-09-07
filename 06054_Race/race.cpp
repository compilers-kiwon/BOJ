#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

typedef	pair<int,int>	State;	// first:-finish_time,second:cow

void	input(int* lap_time,vector<int>* next,int& num_of_cows)
{
	cin>>num_of_cows;
	
	for(int i=1;i<=num_of_cows;i++)
	{
		int	M;
		
		cin>>lap_time[i]>>M;
		
		for(int j=1;j<=M;j++)
		{
			int	A;
			
			cin>>A;
			next[i].push_back(A);
		}
	}
}

int		run(int* lap_time,vector<int>* next,int& num_of_cows)
{
	priority_queue<State>	pq;
	
	bool	finished[MAX_SIZE];
	int		ret;
	
	fill(&finished[1],&finished[num_of_cows+1],false);
	
	pq.push(make_pair(-lap_time[1],1));
	ret = 0;
	finished[1] = true;
	
	for(;!pq.empty();)
	{
		int	current_cow,current_time;
		
		current_time = -pq.top().first;
		current_cow = pq.top().second;
		
		pq.pop();
		ret = max(ret,current_time);
		
		for(int i=0;i<next[current_cow].size();i++)
		{
			int&	next_cow = next[current_cow][i];
			
			if( finished[next_cow] == true )
			{
				continue;
			}
			
			pq.push(make_pair(-(current_time+lap_time[next_cow]),next_cow));
			finished[next_cow] = true;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N,L[MAX_SIZE];
	vector<int>	A[MAX_SIZE];
	
	input(L,A,N);
	cout<<run(L,A,N)<<'\n';
	
	return	0;
}
