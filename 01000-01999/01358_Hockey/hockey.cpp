#include	<iostream>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

bool	is_in_range(int x1,int y1,int x2,int y2,int r)
{
	return	(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))<=(r*r));
}

int		main(void)
{
	int	W,H,X,Y,P,cnt,i,r;
	
	cin>>W>>H>>X>>Y>>P;
	
	for(i=1,cnt=0,r=H/2;i<=P;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		
		if( (IN_RANGE(X,x,X+W) && IN_RANGE(Y,y,Y+H)) || is_in_range(x,y,X,Y+r,r) || is_in_range(x,y,X+W,Y+r,r) )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
