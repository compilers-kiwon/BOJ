#include	<iostream>
#include	<queue>

using namespace	std;

#define	ALICE		0
#define	BOB			1
#define	MAX_PEOPLE	2

#define	NEXT_TRUN(t)	(((t)+1)%MAX_PEOPLE)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					N,value[MAX_PEOPLE];
	priority_queue<int>	piece;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	p;
		
		cin>>p;
		piece.push(p);
	}
	
	for(int i=ALICE;i<MAX_PEOPLE;i++)
	{
		value[i] = 0;
	}
	
	for(int t=ALICE;!piece.empty();t=NEXT_TRUN(t),piece.pop())
	{
		value[t] += piece.top();
	}
	
	for(int i=ALICE;i<MAX_PEOPLE;i++)
	{
		cout<<value[i]<<' ';
	}
	cout<<'\n';
	
	return	0;
}
