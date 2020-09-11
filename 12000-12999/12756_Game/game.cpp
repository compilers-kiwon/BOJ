#include	<iostream>

using namespace	std;

int	main(void)
{
	pair<int,int>	A,B;
	
	cin>>A.first>>A.second>>B.first>>B.second;
	
	for(;A.second>0 && B.second>0;A.second-=B.first,B.second-=A.first);
	
	if( A.second>0 && B.second<=0 )
	{
		cout<<"PLAYER A\n";
	}
	else if( A.second<=0 && B.second>0 )
	{
		cout<<"PLAYER B\n";
	}
	else
	{
		cout<<"DRAW\n";
	}
	
	return	0;
}
