#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	N,len,prev,current,digit,next;
	
	cin>>N;
	
	len = 0;
	prev = 1;
	current = 10;
	digit = 1;
	
	while( N >= current )
	{
		len += (current-prev)*digit;
		
		prev = current;
		current *= 10;
		digit++;
	}
	
	len += (N-prev+1)*digit;
	
	cout<<len<<endl;
	
	digit = 1;
	len = 0;
	next = 10;
	
	for(int i=1;i<=N;i++)
	{
		if( i == next )
		{
			next *= 10;
			digit++;
		}
		
		len += digit;
	}
	cout<<len<<endl;
	return	0;
}
