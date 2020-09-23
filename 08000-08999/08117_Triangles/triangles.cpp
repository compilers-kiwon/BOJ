#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<int>	line;
	bool		found;
	int			a,b,c;
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		line.push_back(n);
	}
	
	found = false;
	
	for(int i=0;i<line.size()-2&&found!=true;i++)
	{
		a = line[i];
		
		for(int j=i+1;j<line.size()-1&&found!=true;j++)
		{
			b = line[j];
			
			for(int k=j+1;k<line.size()&&found!=true;k++)
			{
				c = line[k];
				
				if( a+b>c && a+c>b && b+c>a )
				{
					found = true;
				}
			}
		}
	}
	
	if( found == true )
	{
		cout<<a<<' '<<b<<' '<<c<<'\n';
	}
	else
	{
		cout<<"NIE\n";
	}
	
	return	0;
}
