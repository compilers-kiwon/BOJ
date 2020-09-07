#include	<iostream>

using namespace	std;

#define	MAX_PEOPLE	(50+1)

int	main(void)
{
	int		friend_table[MAX_PEOPLE][MAX_PEOPLE];
	char	input_matrix[MAX_PEOPLE][MAX_PEOPLE+1];
	int		N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			friend_table[i][j] = 1000;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&input_matrix[i][1]);
		
		for(int j=1;j<=N;j++)
		{
			if( input_matrix[i][j] == 'Y' )
			{
				friend_table[i][j] = 1;
			}
		}
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( friend_table[i][j] > friend_table[i][k]+friend_table[k][j] )
				{
					friend_table[i][j] = friend_table[i][k]+friend_table[k][j];
				}
			}
		}
	}
	
	int	max_num_of_friends;
	
	max_num_of_friends = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	cnt_of_friends;
		
		cnt_of_friends = 0;
		friend_table[i][i] = 1000;
		
		for(int j=1;j<=N;j++)
		{
			if( friend_table[i][j] <= 2 )
			{
				cnt_of_friends++;
			}
		}
		
		max_num_of_friends = max(max_num_of_friends,cnt_of_friends);
	}
	
	cout<<max_num_of_friends<<endl;
	
	return	0;
}
