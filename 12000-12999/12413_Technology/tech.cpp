#include	<iostream>
#include	<vector>
#include	<string>
#include	<map>

using namespace	std;

typedef	vector<string>	Required;

void	get_tech(string& src,string& t1,string& t2)
{
	int	i;
	
	for(i=0;src[i]!=' ';i++)
	{
		t1.push_back(src[i]);
	}
	
	for(++i;src[i]!=' ';i++)
	{
		t2.push_back(src[i]);
	}
}

void	input(map<string,Required>& tech_map,Required& goal)
{
	int	M,Q;
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		string	dependency,t1,t2;
		
		cin>>dependency;
		
		dependency.push_back(' ');
		dependency[dependency.find(":")] = ' ';
		
		get_tech(dependency,t1,t2);
		tech_map[t1].push_back(t2);
	}
	
	cin>>Q;
	
	for(int i=1;i<=Q;i++)
	{
		string	t;
		
		cin>>t;
		goal.push_back(t);
	}
}

void	develop_tech(map<string,bool>& developed,
					 map<string,Required>& tech_map,
					 vector<string>& required,
					 vector<string>& result)
{
	for(int i=0;i<required.size();i++)
	{
		string&	t = required[i];
		
		if( developed[t] == false )
		{
			develop_tech(developed,tech_map,tech_map[t],result);
			
			developed[t] = true;
			result.push_back(t);
		}
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
		map<string,Required>	tech_map;
		map<string,bool>		developed;
		Required				goal;
		vector<string>			result;
		
		input(tech_map,goal);
		develop_tech(developed,tech_map,goal,result);
		
		cout<<"Case #"<<t<<": "<<result.size()<<'\n';
		
		for(int i=0;i<result.size();i++)
		{
			cout<<result[i]<<'\n';
		}
	}
	
	return	0;
}
