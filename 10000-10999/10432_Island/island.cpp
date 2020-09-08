#include	<iostream>

using namespace	std;

#define	MAX_SIZE	12

int	get_num_of_island(int* seq)
{
	int	cnt,left,right;
	
	for(cnt=0,left=2;left<=MAX_SIZE-1;left++)
	{
		if( seq[left] <= seq[left-1] )
		{
			continue;
		}
		
		int	min_value;
		
		for(min_value=seq[left],right=left;right<=MAX_SIZE-1;right++)
		{
			min_value = min(min_value,seq[right]);
			
			if( min_value>seq[right+1] && min_value>seq[left-1] )
			{
				cnt++;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	P;
	
	cin>>P;
	
	for(int i=1;i<=P;i++)
	{
		int	T,seq[MAX_SIZE+1];
		
		cin>>T;
		
		for(int j=1;j<=MAX_SIZE;j++)
		{
			cin>>seq[j];
		}
		
		cout<<T<<' '<<get_num_of_island(seq)<<'\n';
	}
	
	return	0;
}
