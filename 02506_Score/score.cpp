#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	int	score,prev,i;
	
	for(i=1,score=prev=0;i<=N;i++)
	{
		int	s;
		
		cin>>s;
		
		if( s == 1 )
		{
			score += ++prev;
		}
		else
		{
			prev = 0;
		}
	}
	cout<<score<<endl;
	
	return	0;
}
