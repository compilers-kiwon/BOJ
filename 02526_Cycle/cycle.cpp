#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	N,P,n,cnt;
	
	cin>>N>>P;
	
	vector<bool>	visited(N,false);
	
	if( N<P )
	{
		visited[N] = true;
		cnt = 1;
	}
	else
	{
		cnt = 0;
	}
	n = N;
	
	while(1)
	{
		n = (n*N)%P;
		
		if( visited[n] == false )
		{
			visited[n] = true;
			cnt++;
		}
		else
		{
			break;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
