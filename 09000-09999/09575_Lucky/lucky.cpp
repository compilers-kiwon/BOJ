#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_SIZE	(50+1)

bool	is_lucky(int n)
{
	bool	result;
	
	for(result=true;n!=0;n/=10)
	{
		if( n%10 != 5 && n%10 != 8 )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		set<int>	lucky_number;
		int			k,a[MAX_SIZE],l,b[MAX_SIZE],m,c[MAX_SIZE];
		
		cin>>k;
		
		for(int i=1;i<=k;i++)
		{
			cin>>a[i];
		}
		
		cin>>l;
		
		for(int i=1;i<=l;i++)
		{
			cin>>b[i];
		}
		
		cin>>m;
		
		for(int i=1;i<=m;i++)
		{
			cin>>c[i];
		}
		
		for(int p=1;p<=k;p++)
		{
			for(int q=1;q<=l;q++)
			{
				for(int r=1;r<=m;r++)
				{
					int	n;
					
					n = a[p]+b[q]+c[r];
									
					if( is_lucky(n) == true )
					{
						lucky_number.insert(n);
					}
				}
			}
		}
		
		cout<<lucky_number.size()<<endl;
		
		T--;
	}
	
	return	0;
}
