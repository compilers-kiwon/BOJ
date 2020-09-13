#include	<iostream>

using namespace	std;

#define	MAX_LEN	200000

int		parent[MAX_LEN];
bool	visited[MAX_LEN];

int		main(void)
{
	int	N,prev,cnt;
	
	cin>>N;
	prev = -1;
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	A;
		
		cin>>A;
		
		if( visited[A] == false )
		{
			visited[A] = true;
			parent[A] = prev;
			cnt++;
		}
		
		prev = A;
	}
	
	cout<<cnt<<'\n';
	
	for(int i=0;i<cnt;i++)
	{
		cout<<parent[i]<<' ';
	}
	cout<<'\n';
	
	return	0;
}
