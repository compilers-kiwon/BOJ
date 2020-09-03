#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Pair;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int				n;
		vector<Pair>	p;
		
		cin>>n;
		
		for(int i=1,to=(n+1)/2;i<to;i++)
		{
			p.push_back(make_pair(i,n-i));
		}
		
		printf("Pairs for %d:",n);
		
		if( p.size() != 0 )
		{
			for(int i=0;i<p.size()-1;i++)
			{
				printf(" %d %d,",p[i].first,p[i].second);
			}
			printf(" %d %d\n",p.back().first,p.back().second);
		}
		else
		{
			puts("");
		}
		
		T--;
	}
	
	return	0;
}
