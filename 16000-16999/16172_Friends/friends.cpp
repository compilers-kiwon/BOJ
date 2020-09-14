#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

string	book1,book2,keyword;

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>book1>>keyword;
	
	for(int i=0;i<book1.length();i++)
	{
		char&	c = book1[i];
		
		if( !IN_RANGE('0',c,'9') )
		{
			book2.push_back(c);
		}
	}
	
	bool	found = false;
	char&	last_c = keyword[keyword.length()-1];
	
	for(int i=keyword.length()-1;i<book2.length()&&found==false;i++)
	{
		if( last_c == book2[i] )
		{
			found = true;
			
			for(int j=0;j<keyword.length();j++)
			{
				if( book2[i-j] != keyword[keyword.length()-1-j] )
				{
					found = false;
					break;
				}
			}
		}
	}
	
	cout<<found<<'\n';
	
	return	0;
}
