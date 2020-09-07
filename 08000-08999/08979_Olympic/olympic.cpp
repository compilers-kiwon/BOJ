#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_NATIONS	(1000+1)

typedef	struct	_NATION_INFO	Nation;
struct	_NATION_INFO
{
	int	n,gold,silver,bronze;
};

Nation	nations[MAX_NUM_OF_NATIONS];
int		N,K;

bool	is_winner(Nation& n1,Nation& n2)
{
	bool	result;
	
	if( n1.gold > n2.gold )
	{
		result = true;
	}
	else if( n1.gold < n2.gold )
	{
		result = false;
	}
	else
	{
		if( n1.silver > n2.silver )
		{
			result = true;
		}
		else if( n1.silver < n2.silver )
		{
			result = false;
		}
		else
		{
			if( n1.bronze > n2.bronze )
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
	}
	
	return	result;
}

void	input(int& index)
{
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d %d %d %d",&nations[i].n,&nations[i].gold,&nations[i].silver,&nations[i].bronze);
		
		if( nations[i].n == K )
		{
			index = i;
		}
	}
}

int		main(void)
{
	int	cnt,i,K_index;
	
	input(K_index);
	
	for(cnt=1,i=1;i<=N;i++)
	{
		if( is_winner(nations[i],nations[K_index]) == true )
		{
			++cnt;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
