#include	<iostream>

using namespace	std;

int	main(void)
{
	int	a3,a2,a1,b3,b2,b1;
	int	score_a,score_b;
	
	cin>>a3>>a2>>a1>>b3>>b2>>b1;
	
	score_a = a3*3+a2*2+a1;
	score_b = b3*3+b2*2+b1;
	
	if( score_a == score_b )
	{
		cout<<"T\n";
	}
	else
	{
		if( score_a > score_b )
		{
			cout<<"A\n";
		}
		else
		{
			cout<<"B\n";
		}
	}
	
	return	0;
}
