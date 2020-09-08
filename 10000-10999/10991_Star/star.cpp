#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int space=N-1,star=1;star<=N;star++,space--)
	{
		string	line(space,' ');
		
		for(int i=1;i<=star;i++)
		{
			line += "* ";
		}
		cout<<line<<endl;
	}
	return	0;
}
