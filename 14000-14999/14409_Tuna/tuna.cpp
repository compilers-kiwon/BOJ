#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

int		main(void)
{
	int	N,X,total_value;
	
	cin>>N>>X;
	total_value = 0;
	
	for(int i=1;i<=N;i++)
	{
		int		p1,p2,p3;
		string	str;
		
		cin>>p1>>p2;
		
		if( abs(p1-p2) <= X )
		{
			total_value += max(p1,p2);
		}
		else
		{
			cin>>p3;
			total_value += p3;
		}
	}
	
	cout<<total_value<<'\n';
	
	return	0;
}
