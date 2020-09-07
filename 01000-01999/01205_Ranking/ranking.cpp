#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	int	N,new_score,P,min_score,new_ranking;
	
	priority_queue<int>	pq;
	
	cin>>N>>new_score>>P;
	
	if( N == 0 )
	{
		cout<<"1\n";
		return	0;
	}
	
	min_score = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		pq.push(n);
		
		if( n < min_score )
		{
			min_score = n;
		}	
	}
	
	if( N==P && new_score<=min_score )
	{
		cout<<"-1\n";
		return	0;
	}
	
	for(new_ranking=1;!pq.empty();new_ranking++)
	{
		if( new_score >= pq.top() )
		{
			break;
		}
		
		pq.pop();
	}
	
	cout<<new_ranking<<'\n';
	
	return	0;
}	
