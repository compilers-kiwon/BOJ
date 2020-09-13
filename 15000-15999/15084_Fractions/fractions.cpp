#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	int2char(i)	((char)((i)+(int)'0'))
#define	char2int(c)	((int)((c)-'0'))
#define	MAX_NUM		100000

bool	visited[MAX_NUM];
	
int	main(void)
{
	int				n,d,f;
	string			fraction;
		
	cin>>n>>d;
	visited[n] = true;
		
	n *= 10;
	f = n/d;
	
	if( f == 0 )
	{
		cout<<"0\n";
		return	0;
	}
	
	if( f == 9 )
	{
		cout<<"1\n";
		return	0;
	}
	
	fraction = "0.";
	fraction.push_back(int2char(f));
		
	for(n%=d;;)
	{
		int		f;
		char&	c = fraction[fraction.length()-1];
	
		if( visited[n] == true )
		{
			fraction = "throw out";
			break;
		}
		
		visited[n] = true;
		
		n *= 10;
		f = n/d;
		
		if( f==0 || f==9 )
		{
			if( f == 9 )
			{
				c = int2char(char2int(c)+1);
			}
			break;
		}
		
		fraction.push_back(int2char(f));
		n %= d;
	}
	
	cout<<fraction<<'\n';
	
	return	0;
}
