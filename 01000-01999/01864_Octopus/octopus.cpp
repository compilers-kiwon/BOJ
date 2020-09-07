#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	BASE				8
#define	char2int(table,c)	((table)[(c)])

void	init(map<char,int>& table)
{
	table['-'] = 0;
	table['\\'] = 1;
	table['('] = 2;
	table['@'] = 3;
	table['?'] = 4;
	table['>'] = 5;
	table['&'] = 6;
	table['%'] = 7;
	table['/'] = -1;
}

int		get_int_val(string& n,map<char,int>& table)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<n.length();i++)
	{
		ret = ret*BASE+char2int(table,n[i]);
	}
	
	return	ret;
}

int		main(void)
{
	map<char,int>	t;
	
	init(t);
	
	for(;;)
	{
		string	n;
		
		cin>>n;
		
		if( n == "#" )
		{
			break;
		}
		
		cout<<get_int_val(n,t)<<'\n';
	}
	
	return	0;
}
