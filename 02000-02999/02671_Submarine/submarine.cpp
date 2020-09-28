#include	<iostream>
#include	<string>

using namespace	std;

#define	STATE_1		1
#define	STATE_2		2
#define	STATE_3		3
#define	STATE_4		4
#define	STATE_5		5
#define	STATE_6		6
#define	MAX_STATE	7

string	str;

bool	dfs(int ptr,int state)
{
	bool	ret;
	
	if( ptr == str.length() )
	{
		bool	ret;
		
		if( state==STATE_4 || state==STATE_6 )
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
		
		return	ret;
	}
	
	char&	c = str[ptr];
	
	switch(state)
	{
		case	STATE_1:
			if( c == '0' )
			{
				ret = dfs(ptr+1,STATE_2);
			}
			else
			{
				ret = false;
			}
			break;
		case	STATE_2:
			if( c == '0' )
			{
				ret = dfs(ptr+1,STATE_3);
			}
			else
			{
				ret = false;
			}
			break;
		case	STATE_3:
			if( c == '0' )
			{
				ret = dfs(ptr+1,STATE_3);
			}
			else
			{
				ret = dfs(ptr+1,STATE_4);
			}
			break;
		case	STATE_4:
			if( c == '0' )
			{
				ret = dfs(ptr+1,STATE_5);
			}
			else
			{
				ret = dfs(ptr+1,STATE_4)||dfs(ptr+1,STATE_1);
			}
			break;
		case	STATE_5:
			if( c == '1' )
			{
				ret = dfs(ptr+1,STATE_6);
			}
			else
			{
				ret = false;
			}
			break;
		case	STATE_6:
			if( c == '1' )
			{
				ret = dfs(ptr+1,STATE_1);
			}
			else
			{
				ret = dfs(ptr+1,STATE_5);
			}
			break;
		default:
			ret = false;
			break;
	}
	
	return	ret;
}

int		main(void)
{
	bool	ret;
	
	cin>>str;
	
	if( str[0] == '1' )
	{
		ret = dfs(1,STATE_1);
	}
	else
	{
		ret = dfs(1,STATE_5);
	}
	
	if( ret == true )
	{
		cout<<"SUBMARINE\n";
	}
	else
	{
		cout<<"NOISE\n";
	}
	
	return	0;
}
