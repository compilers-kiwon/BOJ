#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	N;
	int		len,i;
	
	cin>>N;
	
	for(len=N.length(),i=0;i<len;i=i+10)
	{
		cout<<N.substr(i,10)<<endl;
	}
	
	return	0;	
}
