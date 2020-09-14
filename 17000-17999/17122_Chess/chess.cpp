#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	8

#define	BLACK		0
#define	WHITE		1
#define	MAX_COLOR	2

#define	NEXT_COLOR(c)	(((c)+1)%MAX_COLOR)

int	convert_table[0x100];

int		get_color(const string& str)
{
	int&	row = convert_table[str[1]];
	int&	col = convert_table[str[0]];
	int		ret;
	
	if( row%2 == col%2 )
	{
		ret = BLACK;
	}
	else
	{
		ret = WHITE;
	}
	
	return	ret;
}

int		get_color(int n)
{
	n--;
	
	char	row,col;
	string	s;
	
	row = (char)(n/MAX_SIZE+(int)'1');
	col = (char)(n%MAX_SIZE+(int)'A');
	
	s.push_back(col);
	s.push_back(row);
	
	return	get_color(s);
}

void	init_table(void)
{
	int		n;
	char	c;
	
	for(c='A',n=1;c<='H';c++,n++)
	{
		convert_table[c] = n;
	}
	
	for(c='1',n=1;c<='8';c++,n++)
	{
		convert_table[c] = n;
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	init_table();
	
	for(int i=1;i<=T;i++)
	{
		string	n1;
		int		n2;
		
		cin>>n1>>n2;
		
		if( get_color(n1) == get_color(n2) )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}

	return	0;
}
