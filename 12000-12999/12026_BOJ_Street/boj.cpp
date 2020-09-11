#include	<iostream>

using namespace	std;

#define	MAX_LEN			(1000+1)
#define	NOT_DEFINED		-2
#define	NOT_ACCESSIBLE	-1

int	get_dp(int index,int* energy,char* street)
{
	if( energy[index] == NOT_ACCESSIBLE )
	{
		return	NOT_ACCESSIBLE;
	}
	
	if( energy[index] != NOT_DEFINED )
	{
		return	energy[index];
	}
	
	char	current,prev;
	
	current = street[index];
	
	switch(current)
	{
		case	'B':
			prev = 'J';
			break;
		case	'O':
			prev = 'B';
			break;
		case	'J':
			prev = 'O';
			break;
		default:
			// do nothing
			break;
	}
	
	int	min_energy;
	
	min_energy = 0x7FFFFFFF;
	
	for(int i=1;index-i>=1;i++)
	{
		if( street[index-i] == prev )
		{
			int	e;
			
			e = get_dp(index-i,energy,street);
			
			if( e != NOT_ACCESSIBLE )
			{
				min_energy = min(min_energy,e+i*i);
			}
		}
	}
	
	if( min_energy == 0x7FFFFFFF )
	{
		energy[index] = NOT_ACCESSIBLE;
	}
	else
	{
		energy[index] = min_energy;
	}
	
	return	energy[index];
}

int	main(void)
{
	char	street[MAX_LEN+1];
	int		N,dp[MAX_LEN];

	scanf("%d %s",&N,&street[1]);
	
	for(int i=1;i<=N;i++)
	{
		dp[i] = NOT_DEFINED;
	}
	
	dp[1] = 0;
	
	printf("%d\n",get_dp(N,dp,street));
	
	return	0;	
}
