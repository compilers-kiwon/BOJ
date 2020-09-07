#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_CLASS		(20+1)
#define	MAX_CAPABILITY	(100+1)
#define	MAX_TIME_SLOT	(100+1)

typedef	vector<int>				Time;
typedef	struct{int u,w;Time m;}	Class;

void	input(int& N,int& M,int& C,vector<Class>& class_info)
{
	cin>>N>>M>>C;
	
	for(int i=1;i<=N;i++)
	{
		Class	c;
		int		m;
		
		cin>>c.u>>c.w>>m;
		
		for(int j=1;j<=m;j++)
		{
			int	t;
			
			cin>>t;
			c.m.push_back(t);
		}
		
		if( c.u != 0 )
		{
			class_info.push_back(c);
		}
	}
}

bool	is_available(bool* time_table,Time& m)
{
	for(int i=0;i<m.size();i++)
	{
		if( time_table[m[i]] == true )
		{
			return	false;
		}
	}
	
	return	true;
}

void	get_max_utility(int current_class,vector<Class>& class_info,bool* time_table,
						int current_workload,int current_utility,int& max_utility,int max_capability)
{
	if( current_class == class_info.size() )
	{
		max_utility = max(max_utility,current_utility);
		return;
	}
	
	Class&	current = class_info[current_class];
	
	if( current_workload+current.w<=max_capability && is_available(time_table,current.m)==true )
	{
		for(int i=0;i<current.m.size();i++)
		{
			time_table[current.m[i]] = true;
		}
		
		get_max_utility(current_class+1,class_info,time_table,current_workload+current.w,
						current_utility+current.u,max_utility,max_capability);
						
		for(int i=0;i<current.m.size();i++)
		{
			time_table[current.m[i]] = false;
		}
	}
	
	get_max_utility(current_class+1,class_info,time_table,current_workload,
					current_utility,max_utility,max_capability);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		vector<Class>	class_info;
		bool			time_table[MAX_TIME_SLOT];
		int				N,M,C,max_utility;
		
		input(N,M,C,class_info);
		
		max_utility = 0;
		fill(&time_table[1],&time_table[M+1],false);
		
		get_max_utility(0,class_info,time_table,0,0,max_utility,C);
		cout<<"Data Set "<<k<<":\n"<<max_utility<<'\n';
	}
	
	return	0;
}
