#include	<iostream>

using namespace	std;

typedef	unsigned long long uint64;

int	main(void)
{
	uint64	R,C,N,cnt;
	
	cin>>R>>C>>N;
	
	if( N >= max(R,C) )
	{
		cnt = 1;
	}
	else
	{
		uint64	row,col;
		
		row = R/N+((R%N)?1:0);
		col = C/N+((C%N)?1:0);
		cnt = row*col;
	}
	cout<<cnt<<endl;
	
	return	0;
}
