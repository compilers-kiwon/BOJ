#include	<iostream>
#include	<cmath>

using namespace	std;

bool	one_number(int n)
{
	int	d1,d2,d3;
	
	if( n == 1000 )
	{
		return	false;
	}
	
	bool	result;
	
	d1 = n/100;
	d2 = (n/10)%10;
	d3 = n%10;
	
	if( d1 == d2 && d2 == d3 )
	{
		result = true;
	}
	else if( d1-d2 == d2-d3 )
	{
		result = true;
	}
	else
	{
		result = false;
	}
	
	return	result;
}


int		main(void)
{
	int	N,answer,i;
	
	cin>>N;
	
	if( N<100 )
	{
		answer = N;
	}
	else
	{
		answer = 99;
	}
	
	for(i=100;i<=N;i++)
	{
		if( one_number(i) == true )
		{
			++answer;
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
