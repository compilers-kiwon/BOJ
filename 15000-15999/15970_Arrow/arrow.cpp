#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cmath>

using namespace	std;

#define	MAX_COLOR	(5000+1)
#define	NONE		1000000

int			N,last_color;
vector<int>	point[MAX_COLOR];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		last_color = max(last_color,y);
		
		point[y].push_back(x);
	}
	
	for(int i=1;i<=last_color;i++)
	{
		if( point[i].empty() )
		{
			continue;
		}
		
		point[i].push_back(-NONE);
		point[i].push_back(NONE);
		
		sort(point[i].begin(),point[i].end());
	}
}

int		get_length_of_each_color(int color)
{
	int				ret;
	vector<int>&	p = point[color];
	
	if( p.empty() )
	{
		return	0;
	}
	
	ret = 0;
	
	for(int i=1;i<p.size()-1;i++)
	{
		int&	left = p[i-1];
		int&	right = p[i+1];
		
		ret += min(abs(left-p[i]),abs(right-p[i]));
	}
	
	return	ret;
}

int		get_sum_of_length(void)
{
	int	ret;
	
	ret = 0;
	
	for(int i=1;i<=last_color;i++)
	{
		ret += get_length_of_each_color(i);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_sum_of_length()<<'\n';
	
	return	0;
}
