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
		
		if( str == "������ ����� ��" )
		{
			break;
		}
		
		if( str == "����" )
		{
			num_of_available_problem++;
		}
		
		if( str == "������" )
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
		cout<<"�������� �����\n";
	}
	else
	{
		cout<<"����\n";
	}
	
	return	0;
}
