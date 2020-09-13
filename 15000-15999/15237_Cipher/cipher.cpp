#include	<iostream>
#include	<algorithm>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int				N,C,num[MAX_SIZE];
map<int,int>	cnt,order;

void	init(void)
{
	scanf("%d %d",&N,&C);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
		
		if( order[num[i]] == 0 )
		{
			order[num[i]] = i;
		}
		cnt[num[i]]++;
	}
}

bool	is_more_frequently(const int& a,const int& b)
{
	bool	result;
	
	if( cnt[a] != cnt[b] )
	{
		result = (cnt[a]>cnt[b]);
	}
	else
	{
		result = (order[a]<order[b]);
	}

	return	result;
}

int		main(void)
{
	init();
	
	stable_sort(&num[1],&num[N+1],is_more_frequently);
	
	for(int i=1;i<=N;i++)
	{
		printf("%d ",num[i]);
	}
	puts("");
	
	return	0;
}
