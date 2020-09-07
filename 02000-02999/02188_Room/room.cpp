#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_COW	(200+1)
#define	MAX_NUM_OF_ROOM	(200+1)

#define	NONE	0

int			cow_in_room[MAX_NUM_OF_ROOM],visited[MAX_NUM_OF_COW];
vector<int>	wanted_room[MAX_NUM_OF_COW];

bool	dfs(int current_cow,int level)
{
	if( visited[current_cow] == level )
	{
		return	false;
	}
	
	visited[current_cow] = level;
	
	vector<int>&	candidate_room = wanted_room[current_cow];
	
	for(int i=0;i<candidate_room.size();i++)
	{
		if( cow_in_room[candidate_room[i]] == NONE || dfs(cow_in_room[candidate_room[i]],level) )
		{
			cow_in_room[candidate_room[i]] = current_cow;
			
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	int	N,M,cnt;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	S;
		
		cin>>S;
		
		for(int j=1;j<=S;j++)
		{
			int	r;
			
			cin>>r;
			wanted_room[i].push_back(r);
		}
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( dfs(i,i) == true )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
