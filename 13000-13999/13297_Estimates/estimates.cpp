#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	e;
		
		cin>>e;
		cout<<e.length()<<'\n';
	}
	
	return	0;
}
