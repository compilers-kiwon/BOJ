#include	<iostream>
#include	<map>
#include	<vector>

using namespace	std;

#define	NONE	0

typedef	pair<int,int>	Bridge;

void	input(vector<Bridge>& history,
			  vector<int>& parent,
			  vector<int>& num_of_connected)
{
	int				n,cnt;
	map<string,int>	building;
	
	cin>>n;
	cnt = 0;
	
	for(int i=1;i<=n;i++)
	{
		string	b1,b2;
		
		cin>>b1>>b2;
		
		if( building[b1] == NONE )
		{
			building[b1] = ++cnt;
		}
		
		if( building[b2] == NONE )
		{
			building[b2] = ++cnt;
		}
		
		history.push_back(make_pair(building[b1],building[b2]));
	}
	
	for(int i=0;i<=cnt;i++)
	{
		parent.push_back(i);
		num_of_connected.push_back(1);
	}
}

int		find_parent(int n,vector<int>& parent)
{
	int&	ret = parent[n];
	
	if( n != ret )
	{
		ret = find_parent(ret,parent);
	}
	
	return	ret;
}

void	build_bridge(vector<Bridge>& history,
			  		 vector<int>& parent,
			  		 vector<int>& num_of_connected)
{
	for(int i=0;i<history.size();i++)
	{
		int&	b1 = history[i].first;
		int&	b2 = history[i].second;
		int		p1,p2,big,small;
		
		p1 = find_parent(b1,parent);
		p2 = find_parent(b2,parent);
		
		big = max(p1,p2);
		small = min(p1,p2);
		
		if( big != small )
		{
			parent[big] = small;
			num_of_connected[small] += num_of_connected[big];
		}
		
		cout<<num_of_connected[small]<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		vector<Bridge>	h;
		vector<int>		p,c;
		
		input(h,p,c);
		build_bridge(h,p,c);
	}
	
	return	0;
}
