#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

#define	MIN_BASE	10
#define	MAX_BASE	15000

int	convert_digit(string& num,int base)
{
	return	char2int(num[0])*base*base+char2int(num[1])*base+char2int(num[2]);
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int t=1;t<=K;t++)
	{
		map<int,int>	X_table;
		string			X,Y;
		
		cin>>X>>Y;
		
		for(int b=MIN_BASE;b<=MAX_BASE;b++)
		{
			X_table[convert_digit(X,b)] = b;
		}
		
		for(int b=MIN_BASE;b<=MAX_BASE;b++)
		{
			int	p;
			
			p = X_table[convert_digit(Y,b)];
			
			if( p != 0 )
			{
				cout<<p<<' '<<b<<'\n';
				break;
			}
		}
	}
	
	return	0;
}
