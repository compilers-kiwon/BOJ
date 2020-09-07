#include	<iostream>

using namespace	std;

#define	MAX_PLAY_LIST	(100+1)
#define	MAX_VOLUME		(1000+1)

bool	volume_table[MAX_PLAY_LIST][MAX_VOLUME];
int		volume_list[MAX_PLAY_LIST];

int		main(void)
{
	int	N,S,M;
	
	cin>>N>>S>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>volume_list[i];
	}
	
	volume_table[0][S] = true;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if( volume_table[i-1][j] == true )
			{
				int	v1,v2;
				
				v1 = j-volume_list[i];
				v2 = j+volume_list[i];
				
				if( v1>=0 && v1<=M )
				{
					volume_table[i][v1] = true;
				}
				
				if( v2>=0 && v2<=M )
				{
					volume_table[i][v2] = true;
				}
			}
		}
	}
	
	int	max_volume;
	
	max_volume = -1;
	
	for(int i=0;i<=M;i++)
	{
		if( volume_table[N][i] == true )
		{
			max_volume = i;
		}
	}
	cout<<max_volume<<endl;
	
	return	0;
}
