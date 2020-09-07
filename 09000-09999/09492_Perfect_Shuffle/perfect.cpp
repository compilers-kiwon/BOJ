#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(1000+1)

string	card[MAX_SIZE];

bool	input(int& n)
{
	cin>>n;
	
	if( n == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	
	return	true;
}

void	print(int& n)
{
	int	top_begin,top_end;
	int	bottom_begin,bottom_end;
	int	top_ptr,bottom_ptr;
	
	bottom_begin = (n/2)+((n%2)?2:1);
	bottom_end = n;
	
	top_begin = 1;
	top_end = bottom_begin-1;
	
	for(top_ptr=top_begin,bottom_ptr=bottom_begin;
		top_ptr<=top_end&&bottom_ptr<=bottom_end;
		top_ptr++,bottom_ptr++)
	{
		cout<<card[top_ptr]<<'\n'<<card[bottom_ptr]<<'\n';
	}
	
	if( top_ptr == top_end )
	{
		cout<<card[top_ptr]<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n;
		
		if( input(n) == false )
		{
			break;
		}
		
		print(n);
	}
	
	return	0;
}
