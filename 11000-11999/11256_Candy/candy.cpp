#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		int					J,N;
		priority_queue<int>	box;
		
		cin>>J>>N;
		
		for(int i=1;i<=N;i++)
		{
			int	R,C;
			
			cin>>R>>C;
			box.push(R*C);
		}
		
		int	cnt;
		
		for(cnt=0;J>0;cnt++)
		{
			J -= box.top();
			box.pop();
		}
		
		cout<<cnt<<'\n';
		
		T--;
	}
	
	return	0;
}
