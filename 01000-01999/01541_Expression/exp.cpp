#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

#define	PLUS		'+'
#define	MINUS		'-'
#define	END_OF_EXP	'#'

int	get_num_value(string& str,int& index)
{
	int	value = 0;
	
	for(;index<str.length() && str[index]>='0' && str[index]<='9';index++)
	{
		value = value*10+char2int(str[index]);
	}
	return	value;
}

int	main(void)
{
	string	str;
	int		i,exp,term;
	char	sign;
	
	cin>>str;
	str.push_back(END_OF_EXP);
	i = exp = term = 0;
	sign = PLUS;
	
	while( i<str.length() )
	{
		if( str[i] == PLUS )
		{
			i++;
		}
		else if( str[i] == MINUS || str[i] == END_OF_EXP )
		{
			if( sign == PLUS )
			{
				exp +=term;
			}
			else
			{
				exp -= term;
			}
			
			sign = MINUS;
			term = 0;
			i++;
		}
		else
		{
			term += get_num_value(str,i);
		}
	}
	cout<<exp<<endl;
	
	return	0;
}
