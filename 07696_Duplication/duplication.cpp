#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000000

int	num[MAX_SIZE+1];

int		is_duplicated(int n)
{
	bool	visited[10] = {false,false,false,false,false,
						   false,false,false,false,false};
	
	for(;n>0;n/=10)
	{
		if( visited[n%10] == true )
		{
			return	true;
		}
		
		visited[n%10] = true;
	}
	
	return	false;
}

void	init(void)
{
	for(int i=1,ptr=1;ptr<=MAX_SIZE;i++)
	{
		if( is_duplicated(i) == false )
		{
			num[ptr++] = i;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		cout<<num[n]<<'\n';
	}
	
	return	0;
}
