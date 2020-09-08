#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	vector<int>	answer;
	
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=5;j++)
		{
			answer.push_back(j);
		}
	}
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		vector<int>	submit;
		
		for(int j=1;j<=10;j++)
		{
			int	a;
			
			cin>>a;
			submit.push_back(a);
		}
		
		if( answer == submit )
		{
			cout<<i<<endl;
		}
	}
	
	return	0;
}
