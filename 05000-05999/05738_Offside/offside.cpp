#include	<iostream>
#include	<queue>

using namespace	std;

#define	INF	0x7FFFFFFF

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	A,D;
		
		cin>>A>>D;
		
		if( A==0 && D==0 )
		{
			break;
		}
		
		int	nearest_attack = INF;
		
		for(int i=1;i<=A;i++)
		{
			int	B;
			
			cin>>B;
			nearest_attack = min(nearest_attack,B);
		}
		
		priority_queue<int>	opponent;
		
		for(int i=1;i<=D;i++)
		{
			int	C;
			
			cin>>C;
			opponent.push(-C);
		}
		
		opponent.pop();
		
		int	second_opponent = -opponent.top();
		
		if( nearest_attack >= second_opponent )
		{
			cout<<"N\n";
		}
		else
		{
			cout<<"Y\n";
		}
	}
	
	return	0;
}
