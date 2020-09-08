#include	<iostream>
#include	<string>

using namespace	std;

typedef	long long int	int64;

int		main(void)
{
	int		N;
	string	str;
	int64	cnt_C,cnt_O,cnt_W;
	
	cin>>N>>str;
	cnt_C = cnt_O = cnt_W = 0;
	
	for(int i=0;i<N;i++)
	{
		char&	c = str[i];
		
		switch(c)
		{
			case	'C':
				cnt_C++;
				break;
			case	'O':
				cnt_O += cnt_C;
				break;
			case	'W':
				cnt_W += cnt_O;
				break;
		}
	}
	
	cout<<cnt_W<<'\n';
	
	return	0;
}
