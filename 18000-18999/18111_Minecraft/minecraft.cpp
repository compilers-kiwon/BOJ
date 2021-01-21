#include	<iostream>

using namespace	std;

#define	MAX_HEIGHT	(256+1)
#define	INF			0x7FFFFFFF

int	N,M,B;
int	max_height,min_height;
int	cnt_of_each_height[MAX_HEIGHT];

void	input(void)
{
	cin>>N>>M>>B;
	
	max_height = 0;
	min_height = MAX_HEIGHT;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int	h;
			
			cin>>h;
			cnt_of_each_height[h]++;
			
			max_height = max(max_height,h);
			min_height = min(min_height,h);
		}
	}
}

bool	make_flat(int target_height,int& num_of_operations)
{
	int	num_of_removal,num_of_addition;
	
	num_of_removal = num_of_addition = 0;
	
	for(int h=min_height;h<=max_height;h++)
	{
		if( h < target_height )
		{
			num_of_addition += cnt_of_each_height[h]*(target_height-h);
		}
		
		if( h > target_height )
		{
			num_of_removal += cnt_of_each_height[h]*(h-target_height);
		}
	}
	
	if( num_of_removal+B < num_of_addition )
	{
		return	false;
	}
	
	num_of_operations = 2*num_of_removal+num_of_addition;
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	min_num_of_operations,final_height;
	
	input();
	min_num_of_operations = INF;
	
	for(int h=max_height;h>=min_height;h--)
	{
		int	flat_operation;
		
		if( make_flat(h,flat_operation) && flat_operation<min_num_of_operations )
		{
			final_height = h;
			min_num_of_operations = flat_operation;
		}
	}
	
	cout<<min_num_of_operations<<' '<<final_height<<'\n';
	
	return	0;
}
