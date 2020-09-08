#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		V;
	string	vote;
	
	cin>>V>>vote;
	
	int	A_cnt,B_cnt,i;
	
	for(i=A_cnt=B_cnt=0;i<vote.length();i++)
	{
		if( vote[i] == 'A' )
		{
			A_cnt++;
		}
		else
		{
			B_cnt++;
		}
	}
	
	string	answer;
	
	if( A_cnt > B_cnt )
	{
		answer = "A\n";
	}
	else if( A_cnt < B_cnt )
	{
		answer = "B\n";
	}
	else
	{
		answer = "Tie\n";
	}
	cout<<answer;
	
	return	0;
}
