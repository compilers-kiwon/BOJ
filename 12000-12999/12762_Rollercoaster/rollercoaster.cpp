#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int	N,h[MAX_SIZE];
int	dec_from_left[MAX_SIZE],dec_from_right[MAX_SIZE];

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>h[i];
	}
	
	dec_from_left[1] = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	max_of_prev_higher;
		
		max_of_prev_higher = 0;
		
		for(int j=1;j<i;j++)
		{
			if( h[j]>h[i] && dec_from_left[j]>max_of_prev_higher )
			{
				max_of_prev_higher = dec_from_left[j];
			}
		}
		
		dec_from_left[i] = max_of_prev_higher+1;
	}
	
	dec_from_right[N] = 1;
	
	for(int i=N-1;i>=1;i--)
	{
		int	max_of_prev_higher;
		
		max_of_prev_higher = 0;
		
		for(int j=N;j>i;j--)
		{
			if( h[j]>h[i] && dec_from_right[j]>max_of_prev_higher )
			{
				max_of_prev_higher = dec_from_right[j];
			}
		}
		
		dec_from_right[i] = max_of_prev_higher+1;
	}
	
	int	max_len;
	
	max_len = 0;;
	
	for(int i=1;i<=N;i++)
	{
		max_len = max(max_len,dec_from_left[i]+dec_from_right[i]-1);
	}

	cout<<max_len<<'\n';
	
	return	0;
}
