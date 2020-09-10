#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

typedef	pair<int,string>	Player;

int	main(void)
{
	int	n;
	
	cin>>n;
	
	while(n>0)
	{
		priority_queue<Player>	player_q;
		int	p;
		
		cin>>p;
		
		for(int i=1;i<=p;i++)
		{
			int		C;
			string	name;
			
			cin>>C>>name;
			player_q.push(make_pair(C,name));
		}
		cout<<player_q.top().second<<endl;
		
		n--;
	}
	return	0;
}
