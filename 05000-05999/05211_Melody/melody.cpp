#include	<iostream>
#include	<string>

using namespace	std;

#define	C_MAJOR	1	// C,F,G
#define	A_MINOR	-1	// A,D,E

int	weight[0x100];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	str;
	
	cin>>str;
	str.insert(str.begin(),'|');
	
	weight['C'] = weight['F'] = weight['G'] = C_MAJOR;
	weight['A'] = weight['D'] = weight['E'] = A_MINOR;
	
	int		i,score;
	bool	first_flag;
	
	for(i=score=0,first_flag=false;i<str.length();i++)
	{
		switch(str[i])
		{
			case	'|':
				first_flag = true;
				break;
			default :	// 'A'~'G'
				if( first_flag == true )
				{
					first_flag = false;
					score += weight[str[i]];
				}
				break;
		}
	}
	
	if( score == 0 )
	{
		score = weight[str[str.length()-1]];
	}
	
	if( score > 0 )
	{
		cout<<"C-major\n";
	}
	else
	{
		cout<<"A-minor\n";
	}
	
	return	0;
}
