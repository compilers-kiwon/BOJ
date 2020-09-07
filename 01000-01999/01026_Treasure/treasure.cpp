#include	<iostream>
#include	<queue>

using namespace std;

int		main(void)
{
	int					i,N;
	priority_queue<int>	A,B;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		int	a;
		
		cin>>a;
		A.push(-a);
	}
	
	for(i=1;i<=N;i++)
	{
		int	b;
		
		cin>>b;
		B.push(b);
	}
	
	int	S;
	
	for(S=0,i=1;i<=N;i++)
	{
		int	a,b;
		
		a = -A.top();A.pop();
		b = B.top();B.pop();
		S = S+a*b;
	}
	cout<<S<<endl;
	
	return	0;
}
