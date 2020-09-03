#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

void	input(int& size,int& window,int* sum)
{
	cin>>size>>window;
	sum[0] = 0;
	
	for(int i=1;i<=size;i++)
	{
		int	d;
		
		cin>>d;
		sum[i] = sum[i-1]+d;
	}
}

int		get_difference(int size,int window,int* sum)
{
	int	min_avg,max_avg;
	
	min_avg = 0x7FFFFFFF;
	max_avg = 0;
	
	for(int t=window;t<=size;t++)
	{
		int	avg;
		
		avg = (sum[t]-sum[t-window])/window;
		min_avg = min(min_avg,avg);
		max_avg = max(max_avg,avg);
	}
	
	return	(max_avg-min_avg);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	n,w,sum[MAX_SIZE];
		
		input(n,w,sum);
		cout<<"Data Set "<<k<<":\n"<<get_difference(n,w,sum)<<"\n\n";
	}
	
	return	0;
}
