#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	0x100

char	mirror[MAX_LEN];

void	init(void)
{
	mirror['b'] = 'd';
	mirror['d'] = 'b';
	mirror['p'] = 'q';
	mirror['q'] = 'p';
	mirror['i'] = 'i';
	mirror['o'] = 'o';
	mirror['v'] = 'v';
	mirror['w'] = 'w';
	mirror['x'] = 'x';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(;;)
	{
		string	in,out;
		bool	flag;
		
		cin>>in;
		
		if( in == "#" )
		{
			break;
		}
		
		flag = true;
		
		for(int i=in.length()-1;i>=0;i--)
		{
			char&	c = in[i];
			
			if( mirror[c] != 0 )
			{
				out.push_back(mirror[c]);
			}
			else
			{
				flag = false;
				break;
			}
		}
		
		if( flag == true )
		{
			cout<<out<<'\n';
		}
		else
		{
			cout<<"INVALID\n";
		}
	}
	
	return	0;
}
