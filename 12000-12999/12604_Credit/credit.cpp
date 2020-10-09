#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(2000+1)

typedef	pair<int,int>	Item;

int		C,I;
Item	P[MAX_SIZE];

void	input(void)
{
	cin>>C>>I;
	
	for(int i=1;i<=I;i++)
	{
		cin>>P[i].first;
		P[i].second = i;
	}
}

void	purchase(int& item1,int& item2)
{
	for(int i=1;i<I;i++)
	{
		for(int j=i+1;j<=I;j++)
		{
			if( P[i].first+P[j].first == C )
			{
				item1 = min(P[i].second,P[j].second);
				item2 = max(P[i].second,P[j].second);
				
				return;
			}
			
			if( P[i].first+P[j].first > C )
			{
				break;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int n=1;n<=N;n++)
	{
		int	idx1,idx2;
		
		input();
		sort(&P[1],&P[I+1]);
		
		purchase(idx1,idx2);
		cout<<"Case #"<<n<<": "<<idx1<<' '<<idx2<<'\n';
	}
	
	return	0;
}
