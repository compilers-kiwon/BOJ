#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_STACKS	(50+1)

int	main(void)
{
	cin.sync_with_stdio(false);
	
	for(int s=1;;s++)
	{
		int	n,h[MAX_NUM_OF_STACKS];
		int	num_of_bricks,height_of_wall;
		int	num_of_bricks_to_be_moved;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		num_of_bricks = num_of_bricks_to_be_moved = 0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>h[i];
			num_of_bricks += h[i];
		}
		
		height_of_wall = num_of_bricks/n;
		
		for(int i=1;i<=n;i++)
		{
			if( h[i] > height_of_wall )
			{
				num_of_bricks_to_be_moved += h[i]-height_of_wall;
			}
		}
		
		cout<<"Set #"<<s<<"\nThe minimum number of moves is "<<num_of_bricks_to_be_moved<<".\n\n";
	}
	
	return	0;
}
