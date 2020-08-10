#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_GUITAR	1000
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	char2int(C)			((int)((C)-'0'))

typedef	struct	_GUITAR_INFO	Guitar;
struct	_GUITAR_INFO
{
	string	serial_number;
	int		sum_of_num;
};

int		N;
Guitar	g[MAX_NUM_OF_GUITAR];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		string&	s = g[i].serial_number;
		int&	n = g[i].sum_of_num;
		
		cin>>s;
		n = 0;
		
		for(int j=0;j<s.length();j++)
		{
			if( IN_RANGE('0',s[j],'9') )
			{
				n += char2int(s[j]);
			}
		}
	}
}

bool	is_ahead(const Guitar& g1,const Guitar& g2)
{
	if( g1.serial_number.length() < g2.serial_number.length() )
	{
		return	true;
	}
	else if( g1.serial_number.length() > g2.serial_number.length() )
	{
		return	false;
	}
	else
	{
		if( g1.sum_of_num < g2.sum_of_num )
		{
			return	true;
		}
		else if( g1.sum_of_num > g2.sum_of_num )
		{
			return	false;
		}
	}
	
	return	(g1.serial_number<g2.serial_number);
}

int		main(void)
{
	init();
	sort(&g[0],&g[N],is_ahead);
	
	for(int i=0;i<N;i++)
	{
		cout<<g[i].serial_number<<'\n';
	}
	
	return	0;
}
