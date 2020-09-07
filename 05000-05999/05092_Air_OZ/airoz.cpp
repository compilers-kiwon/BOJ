#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

typedef	pair<int,int>	Product;

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		map<string,Product>	product;
		
		for(int i=1;i<=N;i++)
		{
			string	name;
			int		p,d;
			
			cin>>name>>p>>d;
			product[name] = make_pair(p,d);
		}
		
		int	C,num_of_discontented;
		
		cin>>C;
		num_of_discontented = 0;
		
		for(int i=0;i<C;i++)
		{
			int		n,P,M,value;
			bool	not_purchase;
			
			value = 0;
			not_purchase = false;
			
			cin>>n>>P>>M;
			
			for(int j=1;j<=P;j++)
			{
				string	name;
				
				cin>>name;
				
				if( product[name].second <= M )
				{
					value += product[name].first;
				}
				else
				{
					not_purchase = true;
				}
			}
			
			cout<<n<<' '<<value<<' ';
			
			if( not_purchase == true )
			{
				cout<<"*\n";
				num_of_discontented++;
			}
			else
			{
				cout<<'\n';
			}
		}
		
		cout<<"Number of discontented customers is: "<<num_of_discontented<<'\n';
	}
	
	return	0;
}
