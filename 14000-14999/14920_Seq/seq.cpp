#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned long long	uint64;

int	get_index_of_one(int index,vector<uint64>& C)
{
	uint64	c;
	uint64&	prev = C[index-1];
	
	if( prev%2 == 0 )
	{
		c = prev/2;
	}
	else
	{
		c = 3*prev+1;
	}
	
	if( c == 1 )
	{
		return	index;
	}
	
	C.push_back(c);
	
	return	get_index_of_one(index+1,C);
}

int	main(void)
{
	uint64			first;
	vector<uint64>	C;
	
	cin>>first;
	
	if( first == 1 )
	{
		puts("1");
	}
	else
	{
		C.push_back(0);
		C.push_back(first);
		cout<<get_index_of_one(2,C)<<endl;
	}
	
	return	0;
}
