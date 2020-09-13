#include	<iostream>
#include	<vector>
#include	<map>
#include	<algorithm>

using namespace	std;

typedef	vector<int>	Seq;

#define	MAX_SIZE	(8+1)

int				N,M,n[MAX_SIZE];
map<Seq,bool>	visited;

void	build_seq(int prev_index,Seq& s)
{
	if( s.size() == M )
	{
		if( visited[s] == false )
		{
			visited[s] = true;
			
			for(int i=0;i<M;i++)
			{
				cout<<s[i]<<' ';
			}
			cout<<'\n';
		}
		
		return;
	}
	
	for(int i=prev_index;i<=N;i++)
	{
		s.push_back(n[i]);
		build_seq(i,s);
		s.pop_back();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>n[i];
	}
	
	sort(&n[1],&n[N+1]);
	
	Seq	non_decreasing_seq;
	
	build_seq(1,non_decreasing_seq);
	
	return	0;
}
