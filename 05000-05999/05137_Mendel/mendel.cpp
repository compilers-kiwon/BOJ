#include	<iostream>
#include	<queue>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_INITIAL_TYPES	(10000+1)

int	n,s[MAX_NUM_OF_INITIAL_TYPES],out[MAX_NUM_OF_INITIAL_TYPES];

void	input(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	
	sort(&s[1],&s[n+1]);
}

void	get_combinations(priority_queue<int>& pq)
{
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			int	t;
			
			t = s[i]+s[j];
			
			if( pq.size() < n )
			{
				pq.push(-t);
			}
			else
			{
				if( -pq.top() >= t )
				{
					break;
				}
				
				pq.pop();
				pq.push(-t);
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		priority_queue<int>	pq;
		
		input();
		get_combinations(pq);
		
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=1;!pq.empty();i++)
		{
			out[i] = -pq.top();
			pq.pop();
		}
		
		for(int i=n;i>1;i--)
		{
			cout<<out[i]/2+(out[i]%2)<<' ';
		}
		cout<<out[1]/2+(out[1]%2)<<"\n\n";
	}
	
	return	0;
}
