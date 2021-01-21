#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	str;
	int		N,score,bonus;
	
	cin>>N>>str;
	str.insert(str.begin(),' ');
	
	score = bonus = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( str[i] == 'O' )
		{
			score += i+bonus;
			bonus++;
		}
		else
		{
			bonus = 0;
		}
	}
	
	cout<<score<<'\n';
	
	return	0;
}
