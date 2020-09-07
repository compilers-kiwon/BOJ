#include	<iostream>
#include	<string>

using namespace	std;

#define	BLOCK	'1'
#define	EMPTY	'0'

#define	MAX_HEIGHT			(20+1)
#define	is_fallen(row,i)	(((row)[(i)])==EMPTY&&((row)[(i)+1])==EMPTY)

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int		H;
		string	jenga[MAX_HEIGHT];
		bool	result;
		
		cin>>H;
		result = true;
		
		for(int row=1;row<=H;row++)
		{
			cin>>jenga[row];
		}
		
		for(int row=1;row<=H&&result!=false;row++)
		{
			for(int col=0;col<jenga[row].length()-1&&result!=false;col++)
			{
				if( is_fallen(jenga[row],col) == true )
				{
					result = false;
				}
			}
		}
		
		if( result == false )
		{
			cout<<"Case "<<t<<": "<<"Fallen\n";
		}
		else
		{
			cout<<"Case "<<t<<": "<<"Standing\n";
		}
	}
	
	return	0;
}
