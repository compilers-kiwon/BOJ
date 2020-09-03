#include	<iostream>
#include	<vector>
#include	<set>

using namespace	std;

#define	MAX_PEOPLE	(500+1)

vector<int>	friends[MAX_PEOPLE];

int	main(void)
{
	int	n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	
	set<int>	invite;
	
	for(int i=0;i<friends[1].size();i++)
	{
		invite.insert(friends[1][i]);
		
		for(int j=0;j<friends[friends[1][i]].size();j++)
		{
			invite.insert(friends[friends[1][i]][j]);
		}
	}
	cout<<invite.size()-1<<endl;
	
	return	0;
}
