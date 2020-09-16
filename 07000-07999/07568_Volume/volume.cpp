#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(50+1)

int	main(void)
{
	pair<int,int>	build[MAX_NUM_OF_PEOPLE];
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>build[i].first>>build[i].second;
	}
	
	for(int i=1;i<=N;i++)
	{
		int	cnt = 0;
		
		for(int j=1;j<=N;j++)
		{
			if( build[j].first>build[i].first && build[j].second>build[i].second )
			{
				cnt++;
			}
		}
		cout<<cnt+1<<' ';
	}
	cout<<endl;
	
	return	0;
}
