#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	x1,y1,x2,y2;
		
		cin>>x1>>y1>>x2>>y2;
		
		int	n,cnt;
		
		cin>>n;
		cnt = 0;
		
		for(int i=1;i<=n;i++)
		{
			int	x,y,r,d1,d2;
			
			cin>>x>>y>>r;
			
			d1 = (x1-x)*(x1-x)+(y1-y)*(y1-y);
			d2 = (x2-x)*(x2-x)+(y2-y)*(y2-y);
			r = r*r;
			
			if( (d1<r && d2>r) || (d1>r && d2<r) )
			{
				++cnt;
			}
		}
		cout<<cnt<<endl;
		
		T--;
	}
	
	return	0;
}
