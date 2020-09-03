#include	<iostream>
#include	<string>

using namespace	std;

#define	OFFSET				('a'-'A')
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	const char	replacement[5+1] = {' ','*','?','/','+','!'};
	
	for(;;)
	{
		string	w;
		
		cin>>w;
		
		if( w == "#" )
		{
			break;
		}
		
		int	repeated[0xFF],cnt;
		
		cnt = 1;
		
		for(char c='A';c<='Z';c++)
		{
			repeated[c] = repeated[c+OFFSET] = -1;
		}
		
		for(int i=0;i<w.length();i++)
		{
			char&	c = w[i];
			
			switch(repeated[c])
			{
				case	-1:
					if( IN_RANGE('A',c,'Z') )
					{
						repeated[c] = repeated[c+OFFSET] = 0;
					}
					else
					{
						repeated[c] = repeated[c-OFFSET] = 0;
					}
					cout<<c;
					break;
				case	0:
					if( IN_RANGE('A',c,'Z') )
					{
						repeated[c] = repeated[c+OFFSET] = cnt;
					}
					else
					{
						repeated[c] = repeated[c-OFFSET] = cnt;
					}
					cout<<replacement[cnt];
					cnt++;
					break;
				default :
					cout<<replacement[repeated[c]];
					break;
			}
		}
		cout<<'\n';	
	}
	
	return	0;
}
