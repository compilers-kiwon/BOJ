#include	<iostream>
#include	<string>

using namespace	std;

void	build_line(int N,string& line)
{
	for(int i=1;i<N;i++)
	{
		line += "* ";
	}
	line += "*\n";
}

int		main(void)
{
	int		N;
	string	l;
	
	cin>>N;
	
	build_line(N,l);
	
	for(int i=1;i<=N;i++)
	{
		if( i%2 == 0 )
		{
			cout<<' ';
		}
		cout<<l;
	}
	return	0;
}
