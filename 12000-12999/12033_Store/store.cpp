#include	<iostream>
#include	<map>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_GOODS	8

void	find_discounted(int num_of_goods,map<int,int>& price,vector<int>& discounted)
{
	map<int,int>::iterator	it;
	int						cnt;
	
	for(cnt=0,it=price.begin();it!=price.end()&&cnt<num_of_goods;it++)
	{
		while( it->second != 0 )
		{
			int	origin_price;
			
			origin_price = (it->first/3)*4;
			
			it->second--;
			price[origin_price]--;
			cnt++;
			
			discounted.push_back(it->first);
		}
	}
}

int		main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int				N;
		map<int,int>	price;
		
		cin>>N;
		
		for(int j=1;j<=N*2;j++)
		{
			int	p;
			
			cin>>p;
			price[p]++;
		}
		
		vector<int>	discounted;
		
		find_discounted(N,price,discounted);
		
		cout<<"Case #"<<i<<": ";
		
		for(int j=0;j<N;j++)
		{
			cout<<discounted[j]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
