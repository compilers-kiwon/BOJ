#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

map<string,int>	runner;

int	main(void)
{
	int	N,to;
	
	cin>>N;
	to = 2*N-1;
	
	for(int i=1;i<=to;i++)
	{
		string	name;
		
		cin>>name;
		runner[name]++;
	}
	
	map<string,int>::iterator	iter;
	
	for(iter=runner.begin();iter!=runner.end();iter++)
	{
		if( iter->second%2 != 0 )
		{
			cout<<iter->first;
			break;
		}
	}
	
	return	0;
}
