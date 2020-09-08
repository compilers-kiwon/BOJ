#include	<iostream>
#include	<string>

using namespace	std;

#define	LOWER	0
#define	UPPER	1
#define	NUMBER	2
#define	SPACE	3
#define	MAX_CNT	4

int	main(void)
{
	string	str;
	
	while( getline(cin,str) )
	{
		if( str.length() == 0 )
		{
			break;
		}
		
		int	cnt[MAX_CNT];
		
		for(int i=LOWER;i<=SPACE;i++)
		{
			cnt[i] = 0;
		}
		
		for(int i=0;i<str.length();i++)
		{
			if( 'a'<=str[i] && str[i]<='z' )
			{
				++cnt[LOWER];
			}
			else if( 'A'<=str[i] && str[i]<='Z' )
			{
				++cnt[UPPER];
			}
			else if( '0'<=str[i] && str[i]<='9' )
			{
				++cnt[NUMBER];
			}
			else
			{
				++cnt[SPACE];
			}
		}
		
		for(int i=LOWER;i<=SPACE;i++)
		{
			cout<<cnt[i]<<' ';
		}
		cout<<endl;
	}
	return	0;
}
