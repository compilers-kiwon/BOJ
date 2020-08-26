#include	<iostream>

using namespace	std;

#define	MAX_SIZE		50
#define	MAX_NUM_OF_TEAM	9
#define	EMPTY			'.'

#define	char2int(c)	((int)((c)-'0'))
int	main(void)
{
	char	map[MAX_SIZE][MAX_SIZE+1];
	int		R,C;
	
	scanf("%d %d",&R,&C);
	
	for(int i=0;i<R;i++)
	{
		scanf("%s",&map[i][0]);
	}
	
	int		rank[MAX_NUM_OF_TEAM+1],current_rank;
	
	current_rank = 1;
	
	for(int i=C-2;i>0;i--)
	{
		bool	found;
		
		found = false;
		
		for(int j=0;j<R;j++)
		{
			if( map[j][i] >= '1' && map[j][i] <= '9' )
			{
				found = true;
				rank[char2int(map[j][i])] = current_rank;
				map[j][i] = map[j][i-1] = map[j][i-2] = EMPTY;
			}
		}
		
		if( found == true )
		{
			current_rank++;
		}
	}
	
	for(int i=1;i<=MAX_NUM_OF_TEAM;i++)
	{
		printf("%d\n",rank[i]);
	}
	
	return	0;
}
