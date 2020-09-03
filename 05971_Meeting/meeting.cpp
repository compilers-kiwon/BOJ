#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	NONE		0

int	N,M,parent[MAX_SIZE];

void	get_parents(vector<bool>& p,const int& pasture)
{
	for(int i=pasture;i!=NONE;i=parent[i])
	{
		p[i] = true;
	}
}

int		get_meeting_place(vector<bool>& p,const int& pasture)
{
	int	i;
	
	for(i=pasture;p[i]==false;i=parent[i]);
	
	return	i;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=2;i<=N;i++)
	{
		cin>>parent[i];
	}
	
	for(int i=1;i<=M;i++)
	{
		int				B,J;
		vector<bool>	p(N+1,false);
		
		cin>>B>>J;
		
		get_parents(p,B);
		cout<<get_meeting_place(p,J)<<'\n';
	}
	
	return	0;
}
