#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	SHIFT			1000000000
#define	MAX_SIZE		(25000+1)
#define	NUM_OF_CHOICE	3

typedef	unsigned long long	uint64;
typedef	pair<uint64,int>	Happy;	// first:joy/price,second:index

uint64	P[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int						N;
	priority_queue<Happy>	pq;
	vector<int>				toy;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		uint64	joy;
		
		cin>>joy>>P[i];
		pq.push(make_pair(joy*SHIFT/P[i],i));
	}
	
	uint64	total_price;
	
	total_price = 0;
	
	for(int i=1;i<=NUM_OF_CHOICE;i++)
	{
		int	t;
		
		t = pq.top().second;
		pq.pop();
		
		total_price += P[t];
		toy.push_back(t);
	}
	
	cout<<total_price<<'\n';
	
	for(int i=0;i<toy.size();i++)
	{
		cout<<toy[i]<<'\n';
	}
	
	return	0;
}
