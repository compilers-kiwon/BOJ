#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BOMB	(300000+1)

int		N,num_of_fours[MAX_NUM_OF_BOMB];

void	input(void)
{
	cin>>N;
	
	int	i,sum;
	
	for(i=1;i<=N;i++)
	{
		num_of_fours[i] = 0x7FFFFFFF;
	}
	
	i = 1;
	sum = 1;
	
	while(sum<=N)
	{
		num_of_fours[sum] = 1;
		i++;
		sum += (i+1)*i/2;
	}
}

int		main(void)
{
	input();
	
	for(int i=1;i<=N;i++)
	{
		if( num_of_fours[i] == 1 )
		{
			for(int j=i;j<=N;j++)
			{
				num_of_fours[j] = min(num_of_fours[j-i]+1,num_of_fours[j]);
			}
		}
		
	}
	cout<<num_of_fours[N]<<endl;
	
	return	0;
}
