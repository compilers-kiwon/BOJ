#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	get_score(int n,string& score)
{
	if( IN_RANGE(97,n,100) == true )
	{
		score = "A+";
	}
	else if( IN_RANGE(90,n,96) == true )
	{
		score = "A";
	}
	else if( IN_RANGE(87,n,89) == true )
	{
		score = "B+";
	}
	else if( IN_RANGE(80,n,86) == true )
	{
		score = "B";
	}
	else if( IN_RANGE(77,n,79) == true )
	{
		score = "C+";
	}
	else if( IN_RANGE(70,n,76) == true )
	{
		score = "C";
	}
	else if( IN_RANGE(67,n,69) == true )
	{
		score = "D+";
	}
	else if( IN_RANGE(60,n,66) == true )
	{
		score = "D";
	}
	else
	{
		score = "F";
	}
}

int		main(void)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	name,score;
		int		number;
		
		cin>>name>>number;
		get_score(number,score);
		cout<<name<<' '<<score<<'\n';
	}
	
	return	0;
}
