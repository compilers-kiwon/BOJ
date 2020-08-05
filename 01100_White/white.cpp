#include	<iostream>
#include	<string>

using namespace std;

#define	MAX_SIZE	8

int		main(void)
{
	int	cnt = 0;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		string	line;
		
		cin>>line;
		
		for(int j=i%2;j<MAX_SIZE;j=j+2)
		{
			if( line[j] == 'F' )
			{
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
