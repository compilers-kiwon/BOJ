#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	while(1)
	{
		string	N;
		int		len,i;
		char	prev;
		
		cin>>N;
		
		if( N == "0" )
		{
			break;
		}
		
		for(i=0,len=1,prev=' ';i<N.length();i++,len++)
		{
			if( N[i] == '1' )
			{
				len += 2;
			}
			else if( N[i] == '0' )
			{
				len += 4;
			}
			else
			{
				len += 3;
			}
			
			prev = N[i];
		}
		
		cout<<len<<endl;
	}
	
	return	0;
}
