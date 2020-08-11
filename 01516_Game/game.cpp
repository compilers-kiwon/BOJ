#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_BUILDINGS	(500+1)

typedef	struct	_BUILDING_INFO	Building;
struct	_BUILDING_INFO
{
	int			num_of_pre_built,max_pre_time,my_built_time;
	vector<int>	post_built;
};

int			N,time_table[MAX_NUM_OF_BUILDINGS];
Building	b[MAX_NUM_OF_BUILDINGS];

void		init(queue<int>& building_q)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>b[i].my_built_time;
		
		for(;;)
		{
			int	c;
			
			cin>>c;
			
			if( c == -1 )
			{
				break;
			}
			
			b[c].post_built.push_back(i);
			b[i].num_of_pre_built++;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		if( b[i].num_of_pre_built == 0 )
		{
			building_q.push(i);
		}
	}
}

void		simulate(queue<int>& bq)
{
	for(;!bq.empty();bq.pop())
	{
		int				current_building = bq.front();
		int&			current_time = time_table[current_building];
		vector<int>&	p = b[current_building].post_built;
		
		current_time = b[current_building].max_pre_time+b[current_building].my_built_time;
				
		for(int i=0;i<p.size();i++)
		{
			int&	next_building = p[i];
			
			b[next_building].max_pre_time = max(b[next_building].max_pre_time,current_time);
			
			if( --b[next_building].num_of_pre_built == 0 )
			{
				bq.push(next_building);
			}
		}
	}
}

int		main(void)
{
	queue<int>	bq;
	
	init(bq);
	simulate(bq);
	
	for(int i=1;i<=N;i++)
	{
		cout<<time_table[i]<<'\n';
	}
	
	return	0;
}
