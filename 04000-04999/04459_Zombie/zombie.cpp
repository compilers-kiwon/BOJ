#include	<iostream>
#include	<map>

using namespace	std;

int	main(void)
{
	int				q,r;
	map<int,string>	table;
	
	cin>>q;getchar();
	
	for(int i=1;i<=q;i++)
	{
		getline(cin,table[i]);
	}
	
	cin>>r;getchar();
	
	for(int i=1;i<=r;i++)
	{
		int	n;
		
		cin>>n;
		cout<<"Rule "<<n<<": ";
		
		if( table[n].length() == 0 )
		{
			cout<<"No such rule\n";
		}
		else
		{
			cout<<table[n]<<'\n';
		}
	}
	
	return	0;
}
