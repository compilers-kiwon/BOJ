#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

void	find_level_of_dream(vector<int>& level,vector<int>& real,vector<int>& dream)
{
	int	max_level;
	
	max_level = (dream.size()-real.size())/(real.size()-1);
	
	for(int current_level=0;current_level<=max_level;current_level++)
	{
		bool	found;
		
		found = false;
		
		for(int dream_index=0;dream_index<dream.size();dream_index++)
		{
			if( dream[dream_index] == real.front() )
			{
				int	real_index,dream_tmp_index;
				
				for(real_index=0,dream_tmp_index=dream_index;
					real_index<real.size()&&dream_tmp_index<dream.size();
					real_index++,dream_tmp_index+=current_level+1)
				{
					if( real[real_index] != dream[dream_tmp_index] )
					{
						break;
					}
				}
				
				if( real_index == real.size() )
				{
					found = true;
					break;
				}
			}
		}
		
		if( found == true )
		{
			level.push_back(current_level);
		}	
	}	
}

int		main(void)
{
	int	n,m;
	vector<int>	level,real,dream;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	s;
		
		cin>>s;
		real.push_back(s);
	}
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	s;
		
		cin>>s;
		dream.push_back(s);
	}
	
	find_level_of_dream(level,real,dream);
	
	if( level.size() == 0 )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<level.front()<<' '<<level.back()<<'\n';
	}
	
	return	0;
}
