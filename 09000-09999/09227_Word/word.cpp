#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	is_letter(c)		((IN_RANGE('a',(c),'z')||IN_RANGE('A',(c),'Z')))

bool	dictionary[0x100][0x100];

void	build_dictionary(void)
{
	for(;;)
	{
		string	w;
		
		getline(cin,w);
		
		if( w == "##" )
		{
			break;
		}
		
		dictionary[w[0]][w[1]] = true;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	build_dictionary();
	
	for(;;)
	{
		string	p;
		
		getline(cin,p);
		
		if( p == "#" )
		{
			break;
		}
		
		for(int i=0;i<p.length()-3;i++)
		{
			char&	c1 = p[i+0];
			char&	c2 = p[i+1];
			char&	c3 = p[i+2];
			char&	c4 = p[i+3];
			
			if( dictionary[c1][c4] == true )
			{
				if( is_letter(c2) && is_letter(c3) )
				{
					c2 = c3 = '*';
				}
			}
		}
		
		cout<<p<<'\n';
	}
	
	return	0;
}
