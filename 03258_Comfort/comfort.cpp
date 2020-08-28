#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE				1000
#define	move(pos,offset,size)	(((pos)+(offset))%(size))

bool	is_reachable(int from,int to,int size,int step,bool* available)
{
	bool	visited[MAX_SIZE];
	
	fill(&visited[0],&visited[size],false);
	
	for(int pos=from;pos!=to;)
	{
		if( visited[pos]==true || available[pos]==false )
		{
			return	false;
		}
		
		visited[pos] = true;
		pos = move(pos,step,size);
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,Z,M;
	bool	available[MAX_SIZE];
	
	cin>>N>>Z>>M;
	fill(&available[0],&available[N],true);
	
	for(int i=1;i<=M;i++)
	{
		int	f;
		
		cin>>f;
		available[f-1] = false;
	}
	
	Z--;
	
	for(int K=1;;K++)
	{
		if( is_reachable(0,Z,N,K,available) == true )
		{
			cout<<K<<'\n';
			break;
		}
	}
	
	return	0;
}
