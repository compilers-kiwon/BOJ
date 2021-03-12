#include	<iostream>

using namespace	std;

bool	is_include(int n,int d)
{
	for(;n>0;n/=10)
	{
		if( n%10 == d )
		{
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	int	N,L,max_num=0;
	
	cin>>N>>L;
	
	for(;N>0;)
	{
		max_num++;
		
		if( is_include(max_num,L) == false )
		{
			N--;
		}
	}
	
	cout<<max_num<<'\n';
	
	return	0;
}
