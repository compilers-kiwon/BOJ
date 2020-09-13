#include	<iostream>

using namespace	std;

void	check_solution(int num_of_solutions,bool& result)
{
	for(int i=1;i<=num_of_solutions;i++)
	{
		int	s1,s2;
		
		cin>>s1>>s2;
		
		if( s1 != s2 )
		{
			result = false;	
		}	
	}	
}
		
int		main(void)
{
	int		S1,S2;
	bool	sample_correct,system_correct;
	
	cin>>S1>>S2;
	sample_correct = system_correct = true;
	
	check_solution(S1,sample_correct);
	check_solution(S2,system_correct);
	
	if( sample_correct == false )
	{
		cout<<"Wrong Answer\n";
	}
	else
	{
		if( system_correct == false )
		{
			cout<<"Why Wrong!!!\n";
		}
		else
		{
			cout<<"Accepted\n";
		}
	}
	
	return	0;
}
