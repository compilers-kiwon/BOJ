#include	<iostream>
#include	<map>

using namespace	std;

int	find_num_of_le(int n,map<int,int>& m)
{
	map<int,int>::iterator	it;
	int						cnt;
	
	for(it=m.begin(),cnt=0;it!=m.end()&&it->first<=n;it++)
	{
		cnt += it->second;
	}
	m[n]++;
	
	return	cnt;	
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		map<int,int>	m;
		int				n,sum,i;
		
		cin>>n;
				
		for(sum=0,i=1;i<=n;i++)
		{
			int	a;
			
			cin>>a;
			sum += find_num_of_le(a,m);
		}
		
		cout<<sum<<'\n';
		
		T--;
	}
	
	return	0;
}
