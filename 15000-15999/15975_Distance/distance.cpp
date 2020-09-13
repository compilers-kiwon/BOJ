#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_COLOR	(100000+1)

typedef	long long int	int64;

int				N;
vector<int64>	dot[MAX_COLOR];

void	init(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int64	x;
		int		y;
		
		scanf("%lld %d",&x,&y);
		dot[y].push_back(x);
	}
	
	for(int i=1;i<=N;i++)
	{
		if( dot[i].size() > 1 )
		{
			sort(dot[i].begin(),dot[i].end());
		}
	}
}

int64	get_distance(int color)
{
	int64			sum;
	vector<int64>&	d = dot[color];
	
	sum = (d[1]-d[0])+(d[d.size()-1]-d[d.size()-2]);
	
	for(int i=1,to=d.size()-2;i<=to;i++)
	{
		sum += min(d[i]-d[i-1],d[i+1]-d[i]);
	}
	
	return	sum;
}

int		main(void)
{
	int64	sum_of_distance;
	
	init();
	sum_of_distance = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( dot[i].size() > 1 )
		{
			sum_of_distance += get_distance(i);
		}
	}
	
	printf("%lld\n",sum_of_distance);
	
	return	0;
}
