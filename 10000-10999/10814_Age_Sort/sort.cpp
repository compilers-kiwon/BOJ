#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	pair<int,int>	Record;	// first:age,second:index

int		N;
string	name[MAX_SIZE];
Record	subscriber[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int&	age = subscriber[i].first;
		int&	index = subscriber[i].second;
		
		cin>>age>>name[i];
		index = i;
	}
	
	sort(&subscriber[1],&subscriber[N+1]);
	
	for(int i=1;i<=N;i++)
	{
		cout<<subscriber[i].first<<' '<<name[subscriber[i].second]<<'\n';
	}
	
	return	0;
}
