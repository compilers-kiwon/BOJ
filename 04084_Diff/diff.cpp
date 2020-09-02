#include	<iostream>

using namespace	std;

#define	ABS(n)	(((n)>=0)?(n):-(n))

int	check_diff(int a,int b,int c,int d,int cnt)
{
	if( a==b && b==c && c==d )
	{
		return	cnt;
	}
	
	int	n1,n2,n3,n4;
	
	n1 = ABS(a-b);
	n2 = ABS(b-c);
	n3 = ABS(c-d);
	n4 = ABS(d-a);
	
	return	check_diff(n1,n2,n3,n4,cnt+1);
}

int	main(void)
{
	while(1)
	{
		int	a,b,c,d;
	
		cin>>a>>b>>c>>d;
		
		if( a==0 && b==0 && c==0 && d==0 )
		{
			break;
		}
		
		cout<<check_diff(a,b,c,d,0)<<endl;
	}
	
	return	0;
}
