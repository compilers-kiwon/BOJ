#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		a,b;
	string	op,answer[2];
	
	answer[true] = "true\n";
	answer[false] = "false\n";
	
	for(int i=1;;i++)
	{
		bool	result;
		
		cin>>a>>op>>b;
		
		if( op == "E" )
		{
			break;
		}
		
		if( op == ">" )
		{
			result = a>b;
		}
		else if( op == ">=" )
		{
			result = a>=b;
		}
		else if( op == "<" )
		{
			result = a<b;
		}
		else if( op == "<=" )
		{
			result = a<=b;
		}
		else if( op == "==" )
		{
			result = a==b;
		}
		else
		{
			result = a!=b;
		}
		cout<<"Case "<<i<<": "<<answer[result];
	}
	
	return	0;
}
