#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					N,dasom,cnt;
	priority_queue<int>	candidates;
	
	cin>>N>>dasom;
	
	for(int i=1;i<N;i++)
	{
		int	n;
		
		cin>>n;
		candidates.push(n);
	}
	
	for(cnt=0;!candidates.empty()&&candidates.top()>=dasom;cnt++)
	{
		int	n;
		
		n = candidates.top();
		candidates.pop();
		
		n--;dasom++;
		candidates.push(n);
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
