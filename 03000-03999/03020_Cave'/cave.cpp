#include	<iostream>

using namespace	std;

#define	MAX_LEN_OF_CAVE	(200000+1)
#define	MAX_HEIGHT		(500000+1)

int	num_of_stalagmite_at_each_height[MAX_HEIGHT];
int	num_of_stalactite_at_each_height[MAX_HEIGHT];

int	num_of_crashed_stalagmite_at_each_height[MAX_HEIGHT];
int	num_of_crashed_stalactite_at_each_height[MAX_HEIGHT];

int	N,H;

void	input(void)
{
	scanf("%d %d",&N,&H);
	
	for(int i=1,n=N/2;i<=n;i++)
	{
		int	stalagmite_height,stalactite_height;
		
		scanf("%d %d",&stalagmite_height,&stalactite_height);
		
		num_of_stalagmite_at_each_height[stalagmite_height]++;
		num_of_stalactite_at_each_height[stalactite_height]++;
	}
	
	for(int i=H,prev_stalagmite=0,prev_stalactite=0;i>=1;i--)
	{
		num_of_crashed_stalagmite_at_each_height[i] = prev_stalagmite+num_of_stalagmite_at_each_height[i];
		num_of_crashed_stalactite_at_each_height[i] = prev_stalactite+num_of_stalactite_at_each_height[i];
		
		prev_stalagmite = num_of_crashed_stalagmite_at_each_height[i];
		prev_stalactite = num_of_crashed_stalactite_at_each_height[i];
	}
}

int		main(void)
{
	input();
	
	int	min_num_of_crash,cnt;
	
	min_num_of_crash = 0x7FFFFFFF;
	cnt = 1;
	
	for(int current_height=1;current_height<=H;current_height++)
	{
		int	num_of_crash_at_current_height;
		
		num_of_crash_at_current_height = num_of_crashed_stalagmite_at_each_height[current_height]
										+num_of_crashed_stalactite_at_each_height[H-current_height+1];
		
		if( num_of_crash_at_current_height < min_num_of_crash )
		{
			min_num_of_crash = num_of_crash_at_current_height;
			cnt = 1;
		}
		else if(num_of_crash_at_current_height == min_num_of_crash )
		{
			cnt++;
		}
	}
	printf("%d %d\n",min_num_of_crash,cnt);
	
	return	0;
}
