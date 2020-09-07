#include	<iostream>
#include	<string>

using namespace	std;

#define	PRINT_ERROR()	cout<<"not a quine\n"

int	main(void)
{
	for(;;)
	{
		string str,A,B;
		int		i;
		
		getline(cin,str);
		
		if( str == "END" )
		{
			break;
		}
		
		i = 0;
		
		if( str[i] != '\"' )
		{
			PRINT_ERROR();
			continue;
		}
		
		for(i++;i<str.length()&&str[i]!='\"';i++)
		{
			A.push_back(str[i]);
		}
		
		if( i == str.length() )
		{
			PRINT_ERROR();
			continue;
		}
		
		i++;
		
		if( i==str.length() || str[i]!=' ' )
		{
			PRINT_ERROR();
			continue;
		}
		
		for(i++;i<str.length();i++)
		{
			B.push_back(str[i]);
		}
		
		if( A != B )
		{
			PRINT_ERROR();
			continue;
		}
		
		cout<<"Quine("<<A<<")\n";
	}
	
	return	0;
}
