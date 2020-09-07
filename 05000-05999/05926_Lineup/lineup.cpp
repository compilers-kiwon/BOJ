#include	<iostream>
#include	<algorithm>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	NONE		0

typedef	pair<int,int>	Cow;	// first:pos, second:id

int				N,num_of_ids;
Cow				B[MAX_SIZE];
map<int,bool>	visited;
map<int,int>	lineup;	// lineup[id] = pos

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int&	pos = B[i].first;
		int&	id = B[i].second;
		
		cin>>pos>>id;
		
		if( visited[id] == false )
		{
			num_of_ids++;
			visited[id] = true;
		}
	}
	
	sort(&B[1],&B[N+1]);
}

int		update_width(int& min_pos_cow_id)
{
	int	min_pos,max_pos;
	
	min_pos = 0x7FFFFFFF;
	max_pos = 0;
	
	map<int,int>::iterator	it;
	
	for(it=lineup.begin();it!=lineup.end();it++)
	{
		const int&	id = it->first;
		const int&	pos = it->second;
		
		if( pos < min_pos )
		{
			min_pos_cow_id = id;
			min_pos = pos;
		}
		
		if( pos > max_pos )
		{
			max_pos = pos;
		}
	}
	
	return	max_pos-min_pos; 
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	min_pos_cow,min_width;
	
	min_pos_cow = NONE;
	min_width = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		const int&	pos = B[i].first;
		const int&	id = B[i].second;
		bool		update_flag;
		
		update_flag = false;
		
		if( lineup.size() == num_of_ids )
		{
			lineup[id] = pos;
			
			if( min_pos_cow == id )
			{
				update_flag = true;
			}
		}
		else
		{
			lineup[id] = pos;
			
			if( lineup.size() == num_of_ids )
			{
				update_flag = true;
			}
		}
		
		if( update_flag == true )
		{
			min_width = min(min_width,update_width(min_pos_cow));
		}
	}
	
	cout<<min_width<<'\n';
	
	return	0;	
}
