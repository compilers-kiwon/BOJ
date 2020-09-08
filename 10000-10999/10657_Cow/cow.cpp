#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Cow;

int	main(void)
{
	int			N;
	vector<Cow>	cows;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		int	p,s;
		
		cin>>p>>s;
		cows.push_back(make_pair(p,s));
	}
	
	int	cnt,current_speed;
	
	cnt = 1;
	current_speed = cows[N-1].second;
	
	for(int i=N-2;i>=0;i--)
	{
		if( cows[i].second <= current_speed )
		{
			cnt++;
			current_speed = cows[i].second;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
