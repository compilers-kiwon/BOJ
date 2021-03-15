#include	<iostream>
#include	<map>
#include	<set>
#include	<vector>

using namespace	std;

typedef	vector<int>	Exclusive;

int					N,K;
map<int,Exclusive>	unfriendly;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

void	input(void)
{
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		unfriendly[A].push_back(B);
		unfriendly[B].push_back(A);
	}
}

int		take_picture(void)
{
	int			ret;
	set<int>	current;
	
	map<int,Exclusive>::iterator	it;
	
	for(ret=0,it=unfriendly.begin();it!=unfriendly.end();it++)
	{
		bool			found = false;
		vector<int>&	uf = it->second;
		
		for(int i=0;i<uf.size();i++)
		{
			if( current.find(uf[i]) != current.end() )
			{
				found = true;
				break;
			}
		}
		
		if( found == true )
		{
			ret++;
			current.clear();
			
		}
		
		current.insert(it->first);
	}
	
	if( !current.empty() )
	{
		ret++;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<take_picture()<<'\n';
	
	return	0;
}
