#include	<cstdio>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CARDS	(2000+1)

vector<int>	left(MAX_NUM_OF_CARDS);
vector<int>	right(MAX_NUM_OF_CARDS);

int	N;
int	score_table[MAX_NUM_OF_CARDS][MAX_NUM_OF_CARDS];

int	get_max_score(int left_index,int right_index)
{
	if( left_index > N || right_index > N )
	{
		return	0;
	}
	
	int&	current_score = score_table[left_index][right_index];
	
	if( current_score != -1 )
	{
		return	current_score;
	}
	
	int		sum1,sum2,sum3;
	
	sum1 = sum2 = sum3 = 0;
	
	if( left[left_index] > right[right_index] )
	{
		sum1 = right[right_index]+get_max_score(left_index,right_index+1);
	}
	
	sum2 = get_max_score(left_index+1,right_index+1);
	
	sum3 = get_max_score(left_index+1,right_index);
	
	current_score = max(sum1,max(sum2,sum3));
	
	return	current_score;
}

int	main(void)
{
	int	left_index,right_index;
	
	scanf("%d",&N);
	
	for(left_index=1;left_index<=N;left_index++)
	{
		scanf("%d",&left[left_index]);
	}
	
	for(right_index=1;right_index<=N;right_index++)
	{
		scanf("%d",&right[right_index]);
	}
	
	for(int	i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			score_table[i][j] = -1;
		}
	}
	
	printf("%d\n",get_max_score(1,1));
	
	return	0;	
}
