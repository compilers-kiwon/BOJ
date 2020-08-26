#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_AGENT	5

int	main(void)
{
	int	cnt = 0;
	
	for(int i=1;i<=NUM_OF_AGENT;i++)
	{
		string	name;
		
		cin>>name;
		if( name.find("FBI") != string::npos )
		{
			cout<<i<<' ';
			cnt++;
		}
	}
	
	if( cnt == 0 )
	{
		cout<<"HE GOT AWAY!";
	}
	cout<<endl;
	
	return	0;
}
