#include	<iostream>

using namespace std;

#define	BIG			0
#define	MID			1
#define	SMALL		2
#define	MAX_SIZE	3

int		get_length(int a,int b,int c,int* result)
{
	result[BIG] = max(a,max(b,c));
	
	if( result[BIG] == a )
	{
		result[MID] = max(b,c);
		result[SMALL] = min(b,c);
	}
	else if( result[BIG] == b )
	{
		result[MID] = max(a,c);
		result[SMALL] = min(a,c);
	}
	else
	{
		result[MID] = max(a,b);
		result[SMALL] = min(a,b);
	}
	
	return	a+b+c;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	a,b,c,sorted[MAX_SIZE],max_len;

	max_len = 0;	
	cin>>a>>b>>c;

	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=c;k++)
			{
				int	len;
				
				len = get_length(i,j,k,sorted);
				
				if( sorted[MID]+sorted[SMALL] > sorted[BIG] )
				{
					max_len = max(max_len,len);
				}
			}
		}
	}
	
	cout<<max_len<<'\n';
	
	return	0;
}
