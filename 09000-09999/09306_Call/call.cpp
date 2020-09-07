#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	first,last;
		
		cin>>first>>last;
		cout<<"Case "<<i<<": "<<last<<", "<<first<<'\n';
	}
	
	return	0;
}
