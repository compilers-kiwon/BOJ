#include	<iostream>
#include	<vector>
#include	<set>
#include	<algorithm>

using namespace	std;

typedef	pair<int,int>	Cow;	// first:time, second:index

void	init(int& num_of_lifeguards,vector<Cow>& work)
{
	cin>>num_of_lifeguards;
	
	for(int i=0;i<num_of_lifeguards;i++)
	{
		int	from,to;
		
		cin>>from>>to;
		work.push_back(make_pair(from,i));
		work.push_back(make_pair(to,i));
	}
	
	sort(work.begin(),work.end());
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N;
	vector<Cow>	cow;
	
	init(N,cow);
	
	vector<bool>	is_working(N,false);
	vector<int>		working_time(N,0);
	set<int>		working_cow;
	int				prev_time,total_working_time;
	
	prev_time = total_working_time = 0;
	
	for(int i=0;i<cow.size();i++)
	{
		int&	current_cow = cow[i].second;
		int&	current_time = cow[i].first;
		
		if( working_cow.size() == 1 )
		{
			working_time[*(working_cow.begin())] += current_time-prev_time;
		}
		
		if( working_cow.empty() == false )
		{
			total_working_time += current_time-prev_time;
		}
		
		if( is_working[current_cow] == true )
		{
			is_working[current_cow] = false;
			working_cow.erase(current_cow);
		}
		else
		{
			is_working[current_cow] = true;
			working_cow.insert(current_cow);
		}
		
		prev_time = current_time;
	}
	
	int	min_time_to_work_alone;
	
	min_time_to_work_alone = 0x7FFFFFFF;
	
	for(int i=0;i<N;i++)
	{
		min_time_to_work_alone = min(min_time_to_work_alone,working_time[i]);
	}
	
	cout<<total_working_time-min_time_to_work_alone<<'\n';
	
	return	0;
}
