#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(20+1)

typedef	long long int		int64;
typedef	pair<int64,int64>	Pos;	// first:x,second:y

int		N;
Pos		p[MAX_SIZE];
bool	selected[MAX_SIZE];

int64	get_vectors(void)
{
	int64	x,y;
	
	x = y = 0;

	for(int i=1;i<=N;i++)
	{
		if( selected[i] == true )
		{
			x += p[i].first;
			y += p[i].second;
		}
		else
		{
			x -= p[i].first;
			y -= p[i].second;
		}
	}

	return	(x*x+y*y);
}

void	dfs(int s,int num_of_selected,int64& min_value)
{
	if( s > N )
	{
		if( num_of_selected == N/2 )
		{
			min_value = min(min_value,get_vectors());
		}
		
		return;
	}
	
	selected[s] = true;
	dfs(s+1,num_of_selected+1,min_value);
	selected[s] = false;
		
	dfs(s+1,num_of_selected,min_value);
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int64	min_value;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			cin>>p[i].first>>p[i].second;
			selected[i] = false;
		}
		
		min_value = 0x7FFFFFFFFFFFFFFF;
		dfs(1,0,min_value);
		
		printf("%.6f\n",sqrt((double)min_value));
	}
	
	return	0;
}
