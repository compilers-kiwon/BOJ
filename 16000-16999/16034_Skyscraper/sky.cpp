#include	<iostream>

using namespace	std;

#define	MAX_SIZE	45000

int	get_size_of_sequence(const int& n,int& min_num)
{
	int	size;
	
	for(size=MAX_SIZE;size>=0;size--)
	{
		int	a,b;
		
		a = 2*n-size*size+size;
		
		if( a <= 0 )
		{
			continue;
		}
		
		b = 2*size;
		
		if( a%b == 0  )
		{
			min_num = a/b;
			return	size;
		}
	}
	
	min_num = n;
	
	return	1;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	b,s,h;
		
		cin>>b;
		
		if( b == 0 )
		{
			break;
		}
		
		h = get_size_of_sequence(b,s);
		cout<<s<<' '<<h<<'\n';
	}
	
	return	0;
}
