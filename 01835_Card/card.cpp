#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int			N,card[MAX_SIZE];
queue<int>	card_q;

int	main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		card_q.push(i);
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=i;j++)
		{
			card_q.push(card_q.front());
			card_q.pop();
		}
		
		card[card_q.front()] = i;
		card_q.pop();
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<card[i]<<' ';
	}
	cout<<'\n';

	return	0;
}
