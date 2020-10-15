#include	<iostream>
#include	<stack>
#include	<string>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int				N,cost;
		stack<string>	deck;
		
		cin>>N;getchar();
		cost = 0;
		
		for(int i=1;i<=N;i++)
		{
			string	card;
			
			getline(cin,card);
			
			if( deck.empty() || card>=deck.top() )
			{
				deck.push(card);
			}
			else
			{
				cost++;
			}
		}
		
		cout<<"Case #"<<t<<": "<<cost<<'\n';
	}
	
	return	0;
}
