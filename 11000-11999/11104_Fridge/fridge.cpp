#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	n;
	
	cin>>n;
	
	while(n>0)
	{
		string	bin;
		int		d,i;
		
		cin>>bin;
		
		for(i=0,d=0;i<bin.length();i++)
		{
			d = d*2+(int)(bin[i]-'0');
		}
		cout<<d<<endl;
		
		n--;
	}
	
	return	0;
}
