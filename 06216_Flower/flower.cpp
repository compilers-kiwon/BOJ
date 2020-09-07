#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_COW	(100000+1)

typedef	unsigned long long	uint64;
typedef	pair<uint64,uint64>	Cow;

int		N;
Cow		cow[MAX_NUM_OF_COW];
uint64	left_time[MAX_NUM_OF_COW];

bool	is_earlier(const Cow& first,const Cow& second)
{
	return	(first.second*second.first>second.second*first.first);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>cow[i].first>>cow[i].second;
	}
	
	sort(&cow[1],&cow[N+1],is_earlier);
	
	uint64	acc_time,num_of_destroyed_flowers;
	
	acc_time = num_of_destroyed_flowers = 0;
	
	for(int i=1;i<=N;i++)
	{
		left_time[i] = acc_time;
		acc_time += cow[i].first*2;
	}
	
	for(int i=1;i<=N;i++)
	{
		num_of_destroyed_flowers += left_time[i]*cow[i].second;
	}
	
	cout<<num_of_destroyed_flowers<<'\n';
	
	return	0;
}
