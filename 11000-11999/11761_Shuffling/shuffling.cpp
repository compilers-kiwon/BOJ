#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	1000

void	out_shuffles(int* deck,int first_half_index,
					 int second_half_index,int deck_size)
{
	int	tmp[MAX_SIZE];
	
	for(int i=first_half_index,j=0;i<second_half_index;i++,j+=2)
	{
		tmp[j] = deck[i];
	}
	
	for(int i=second_half_index,j=1;i<deck_size;i++,j+=2)
	{
		tmp[j] = deck[i];
	}
	
	for(int i=0;i<deck_size;i++)
	{
		deck[i] = tmp[i];
	}
}

void	in_shuffles(int* deck,int first_half_index,
					 int second_half_index,int deck_size)
{
	int	tmp[MAX_SIZE];
	
	for(int i=first_half_index,j=1;i<second_half_index;i++,j+=2)
	{
		tmp[j] = deck[i];
	}
	
	for(int i=second_half_index,j=0;i<deck_size;i++,j+=2)
	{
		tmp[j] = deck[i];
	}
	
	for(int i=0;i<deck_size;i++)
	{
		deck[i] = tmp[i];
	}
}

int	main(void)
{
	int		n,cnt,first_half_index,second_half_index,deck[MAX_SIZE];
	string	t;
	
	cin>>n>>t;
	
	for(int i=0;i<n;i++)
	{
		deck[i] = i;
	}
	
	first_half_index = 0;
	
	if( n%2 == 0 )
	{
		second_half_index = n/2;
	}
	else
	{
		if( t == "out" )
		{
			second_half_index = (n/2)+1;
		}
		else
		{
			second_half_index = n/2;
		}
	}
	
	if( t == "out" )
	{
		for(cnt=1;;cnt++)
		{
			out_shuffles(deck,first_half_index,second_half_index,n);
			
			bool	is_original_state;
			
			is_original_state = true;
			
			for(int i=0;i<n;i++)
			{
				if( deck[i] != i )
				{
					is_original_state = false;
					break;
				}
			}
			
			if( is_original_state == true )
			{
				break;
			}
		}
	}
	else
	{
		for(cnt=1;;cnt++)
		{
			in_shuffles(deck,first_half_index,second_half_index,n);
			
			bool	is_original_state;
			
			is_original_state = true;
			
			for(int i=0;i<n;i++)
			{
				if( deck[i] != i )
				{
					is_original_state = false;
					break;
				}
			}
			
			if( is_original_state == true )
			{
				break;
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
