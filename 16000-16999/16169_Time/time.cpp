#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

typedef	struct{int i,t;}	Computer;	// i: computer index, t:operation time
typedef	pair<int,int>		Time;		// first:computer index, second: time to be spent

#define	MAX_LEVEL	(100+1)

int					n,max_level;
vector<Computer>	c[MAX_LEVEL];
vector<Time>		time_table[MAX_LEVEL];

void	init(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		Computer	tmp;
		int			level;
		
		cin>>level>>tmp.t;
		tmp.i = i;
		
		c[level].push_back(tmp);
		
		if( level == 1 )
		{
			time_table[1].push_back(make_pair(i,tmp.t));
		}
		
		max_level = max(max_level,level);
	}
}

void	update_time_table(int current_level)
{
	vector<Time>&	current = time_table[current_level];
	vector<Time>&	prev = time_table[current_level-1];
	
	for(int i=0;i<c[current_level].size();i++)
	{
		Computer&	pc = c[current_level][i];
		int			t;
		
		t = 0;
		
		for(int j=0;j<prev.size();j++)
		{
			int&	prev_index = prev[j].first;
			int&	prev_time = prev[j].second;
			
			t = max(t,prev_time+pc.t+(pc.i-prev_index)*(pc.i-prev_index));
		}
		
		current.push_back(make_pair(pc.i,t));
	}
}

int		get_max_time(void)
{
	int	t;
	
	t = 0;
	
	for(int i=0;i<time_table[max_level].size();i++)
	{
		t = max(t,time_table[max_level][i].second);
	}
	
	return	t;
}

int		main(void)
{
	init();
	
	for(int i=2;i<=max_level;i++)
	{
		update_time_table(i);
	}
	
	cout<<get_max_time()<<'\n';
	
	return	0;
}
