#include	<iostream>
#include	<string>

using namespace	std;

#define	OFFSET	('a'-'A')

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{	
	for(bool flag = false;;)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "" )
		{
			break;
		}
		
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			
			if( IN_RANGE('a',c,'z') )
			{
				if( flag == true )
				{
					c -= OFFSET;
					flag = false;
				}
				continue;
			}
			
			if( IN_RANGE('A',c,'Z') )
			{
				if( flag == true )
				{
					flag = false;
				}
				else
				{
					c += OFFSET;
				}
				continue;
			}
			
			if( IN_RANGE('0',c,'9') )
			{
				if( flag == true )
				{
					flag = false;
				}
				continue;
			}
			
			if( c=='.' || c=='?' || c=='!' )
			{
				flag = true;
			}
		}
		
		cout<<str<<'\n';
	}
	
	return	0;
}
