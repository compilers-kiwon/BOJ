#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_POINT	100000

pair<int,int>	p[MAX_NUM_OF_POINT];

bool	is_less(pair<int,int> p1,pair<int,int> p2)
{
	bool	result;
	
	if( p1.first < p2.first )
	{
		result = true;
	}
	else if( p1.first == p2.first )
	{
		if( p1.second < p2.second )
		{
			result = true;
		}
		else
		{
			result = false;
		}
	}
	else
	{
		result = false;
	}

	return	result;
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&p[i].first,&p[i].second);
	}
	
	sort(&p[0],&p[N],is_less);
	
	for(int i=0;i<N;i++)
	{
		printf("%d %d\n",p[i].first,p[i].second);
	}
	
	return	0;
}	
