#include	<iostream>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	MAX_NUM	1000000

void	get_sum_of_divisor(vector<int>& diff)
{
	for(int i=1;i<MAX_NUM;i++)
	{
		for(int j=i+i;j<MAX_NUM;j+=i)
		{
			diff[j] += i;
		}
		diff[i] = abs(i-diff[i]);
	}
}

int		main(void)
{
	vector<int>	diff(MAX_NUM,0);
	
	get_sum_of_divisor(diff);
	
	for(int t=1;;t++)
	{
		int	start,stop,badness,cnt;
		
		scanf("%d %d %d",&start,&stop,&badness);
		
		if( start==0 && stop==0 && badness==0 )
		{
			break;
		}
		
		cnt = 0;
		
		for(int i=start;i<=stop;i++)
		{
			if( diff[i] <= badness )
			{
				cnt++;
			}
		}
		
		printf("Test %d: %d\n",t,cnt);
	}
	
	return	0;
}
