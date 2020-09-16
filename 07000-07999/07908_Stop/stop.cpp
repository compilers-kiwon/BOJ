#include	<iostream>
#include	<set>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64		n;
	set<uint64>	visited;
	bool		result;
	
	cin>>n;
	
	for(result=true;n>1;)
	{
		if( visited.find(n) != visited.end() )
		{
			result = false;
			break;
		}
		
		visited.insert(n);
		
		if( n%2 == 0 )
		{
			n /= 2;
		}
		else
		{
			n = n*3+3;
		}
	}
	
	if( result == false )
	{
		cout<<"NIE\n";
	}
	else
	{
		cout<<"TAK\n";
	}
	
	return	0;
}
