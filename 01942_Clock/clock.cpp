#include	<iostream>
#include	<string>

using namespace	std;

int	go_time(int h1,int m1,int s1,int h2,int m2,int s2)
{
	int	cnt;
	
	if( (h1*10000+m1*100+s1)%3 == 0 )
	{
		cnt = 1;
	}
	else
	{
		cnt = 0;
	}
	
	while( !(h1==h2&&m1==m2&&s1==s2) )
	{
		s1++;
		
		if( s1 == 60 )
		{
			s1 = 0;
			m1++;
			
			if( m1 == 60 )
			{
				m1 = 0;
				h1++;
				
				if( h1 == 24 )
				{
					h1 = 0;
				}
			}
		}
		
		if( (h1*10000+m1*100+s1)%3 == 0 )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	while(1)
	{
		string	str;
		int		h1,m1,s1,h2,m2,s2;
		
		getline(cin,str);
		
		if( str == "" )
		{
			break;
		}
		
		str[2] = str[5] = str[11] = str[14] = ' ';
		sscanf(str.c_str(),"%d %d %d %d %d %d",&h1,&m1,&s1,&h2,&m2,&s2);
		
		printf("%d\n",go_time(h1,m1,s1,h2,m2,s2));
	}
	
	return	0;
}
