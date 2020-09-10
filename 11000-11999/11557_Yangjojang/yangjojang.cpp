#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

typedef	pair<int,string>	University;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N;
		
		priority_queue<University>	pq;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			int		drink;
			string	name;
			
			cin>>name>>drink;
			pq.push(make_pair(drink,name));
		}
		cout<<pq.top().second<<endl;
		
		T--;
	}
	return	0;
}
