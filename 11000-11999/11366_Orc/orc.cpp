#include	<iostream>

using namespace	std;

int	main(void)
{
	for(;;)
	{
		int	a,b,c;
		
		cin>>a>>b>>c;
		
		if( a==0 && b==0 && c==0 )
		{
			break;
		}
		
		if( a==0 && b==0 )
		{
			cout<<"0\n";
			continue;
		}
		
		int	prev_2,prev_1,current;
		
		prev_2 = a;
		prev_1 = b;
		
		for(int i=1;i<=c;i++)
		{
			current = prev_2+prev_1;
			prev_2 = prev_1;
			prev_1 = current;
		}
		
		cout<<current<<'\n';
	}
	
	return	0;
}
