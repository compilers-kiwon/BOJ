#include	<iostream>

using namespace	std;

#define	MAX_ALUMNI	(100+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N,D,attended[MAX_ALUMNI];
		
		cin>>N>>D;
		
		if( N==0 && D==0 )
		{
			break;
		}
		
		fill(&attended[1],&attended[N+1],0);
		
		for(int i=1;i<=D;i++)
		{
			for(int j=1;j<=N;j++)
			{
				int	n;
				
				cin>>n;
				attended[j] += n;
			}
		}
		
		bool	attended_all_dinner;
		
		attended_all_dinner = false;
		
		for(int i=1;i<=N;i++)
		{
			if( attended[i] == D )
			{
				attended_all_dinner = true;
				break;
			}
		}
		
		if( attended_all_dinner == true )
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	
	return	0;
}
