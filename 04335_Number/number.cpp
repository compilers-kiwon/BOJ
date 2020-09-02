#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	LOWER	1
#define	BIGGER	2

typedef	pair<int,int>	State;

bool	is_honest(vector<State>& s,int n)
{
	bool	ret;
	int		i;
	
	for(i=0,ret=true;i<s.size();i++)
	{
		int&	query = s[i].first;
		int&	comp = s[i].second;
		
		if( (comp==LOWER && query>=n) || (comp==BIGGER && query<=n) )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				n;
		string			s1,s2;
		vector<State>	s;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		for(;;)
		{
			cin>>s1>>s2;
			
			if( s2 == "on" )
			{
				break;
			}
			
			if( s2 == "high" )
			{
				s.push_back(make_pair(n,BIGGER));
			}
			else
			{
				s.push_back(make_pair(n,LOWER));
			}
			
			cin>>n;
		}
		
		if( is_honest(s,n) == true )
		{
			cout<<"Stan may be honest\n";
		}
		else
		{
			cout<<"Stan is dishonest\n";
		}
	}
	
	return	0;
}
