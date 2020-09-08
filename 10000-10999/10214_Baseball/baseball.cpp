#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	y_score,k_score,i;
		
		for(i=1,y_score=k_score=0;i<=9;i++)
		{
			int	Y,K;
			
			cin>>Y>>K;
			y_score += Y;
			k_score += K;
		}
		
		if( y_score == k_score )
		{
			cout<<"Draw\n";
		}
		else if( y_score > k_score )
		{
			cout<<"Yonsei\n";
		}
		else
		{
			cout<<"Korea\n";
		}
		
		T--;
	}
	return	0;
}
