#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		num_of_available_problem;
	string	str;
	
	getline(cin,str);
	num_of_available_problem = 0;
	
	for(;;)
	{
		getline(cin,str);
		
		if( str == "고무오리 디버깅 끝" )
		{
			break;
		}
		
		if( str == "문제" )
		{
			num_of_available_problem++;
		}
		
		if( str == "고무오리" )
		{
			if( num_of_available_problem == 0 )
			{
				num_of_available_problem += 2;	
			}
			else
			{
				num_of_available_problem--;
			}
		}
	}
	
	if( num_of_available_problem == 0 )
	{
		cout<<"고무오리야 사랑해\n";
	}
	else
	{
		cout<<"힝구\n";
	}
	
	return	0;
}
