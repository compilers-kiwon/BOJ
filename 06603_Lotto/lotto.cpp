#include	<cstdio>

using namespace	std;

#define	MAX_SIZE			13
#define	NUM_OF_SELCTED_NUMS	6

int		candidates[MAX_SIZE];
int		selected[NUM_OF_SELCTED_NUMS+1];

void	print(void)
{
	for(int i=1;i<=NUM_OF_SELCTED_NUMS;i++)
	{
		printf("%d ",selected[i]);
	}
	puts("");
}

void	select_number(int index_of_number_to_be_selected_already,
					  int start_index_of_prev_candidates,int num_of_candidates)
{
	if( index_of_number_to_be_selected_already == NUM_OF_SELCTED_NUMS )
	{
		print();
		return;
	}
	
	int	num_of_candidates_to_be_selected_more;
	
	num_of_candidates_to_be_selected_more = 
		NUM_OF_SELCTED_NUMS-index_of_number_to_be_selected_already;
	
	if( num_of_candidates_to_be_selected_more == num_of_candidates-start_index_of_prev_candidates )
	{
		for(int i=start_index_of_prev_candidates+1,j=index_of_number_to_be_selected_already+1;
			j<=NUM_OF_SELCTED_NUMS;i++,j++)
		{
			selected[j] = candidates[i];
		}
		print();
		return;
	}
	
	int	current_index = index_of_number_to_be_selected_already+1;
	
	for(int i=start_index_of_prev_candidates+1;i<=num_of_candidates-num_of_candidates_to_be_selected_more+1;i++)
	{
		selected[current_index] = candidates[i];
		select_number(current_index,i,num_of_candidates);
	}
}

int		main(void)
{
	while(1)
	{
		int	k;
		
		scanf("%d",&k);
		
		if( k == 0 )
		{
			break;
		}
		
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&candidates[i]);
		}
		select_number(0,0,k);
		puts("");
	}
	return	0;
}
