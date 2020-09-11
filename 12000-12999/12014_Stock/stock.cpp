#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

int	is_possible_to_purchase(vector<int>& stock_price,int K)
{
	int			result,i;
	vector<int>	lis;
	
	for(i=0,result=FALSE;i<stock_price.size();i++)
	{
		int	l;
		
		l = lower_bound(lis.begin(),lis.end(),stock_price[i])-lis.begin();
		
		if( l == lis.size() )
		{
			lis.push_back(stock_price[i]);
		}
		else
		{
			lis[l] = stock_price[i];
		}
		
		if( lis.size() == K )
		{
			result = TRUE;
			break;
		}
	}
	
	return	result;
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int j=1;j<=T;j++)
	{
		int	N,K;
		
		vector<int>	s;
		
		cin>>N>>K;
		
		for(int i=1;i<=N;i++)
		{
			int	n;
			
			cin>>n;
			s.push_back(n);
		}
		
		cout<<"Case #"<<j<<'\n'<<is_possible_to_purchase(s,K)<<'\n';
	}
	
	return	0;
}
