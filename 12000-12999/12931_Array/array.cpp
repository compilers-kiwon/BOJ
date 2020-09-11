#include	<iostream>
#include	<vector>

using namespace	std;

typedef	vector<short>	Array;

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int		N,min_num_of_operation;
	
	cin>>N;
	
	Array			init(N,0),final(N);
		
	for(int i=0;i<N;i++)
	{
		cin>>final[i];
	}
		
	for(min_num_of_operation=0;;min_num_of_operation++)
	{
		if( init == final )
		{
			break;
		}
		
		bool	is_even;
		int		i;
		
		for(is_even=true,i=0;i<N;i++)
		{
			if( final[i]%2 != 0 )
			{
				is_even = false;
				break;
			}
		}
		
		if( is_even == false )
		{
			final[i]--;
		}
		else
		{
			for(i=0;i<N;i++)
			{
				final[i] /= 2;
			}
		}
	}
	
	cout<<min_num_of_operation<<'\n';
	
	return	0;
}
