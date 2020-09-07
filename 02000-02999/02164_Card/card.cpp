#include	<iostream>
#include	<queue>

using namespace	std;

queue<int>	card;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		card.push(i);
	}
	
	while( card.size() != 1 )
	{
		card.pop();
		card.push(card.front());
		card.pop();
	}
	cout<<card.front()<<endl;
	
	return	0;
}
