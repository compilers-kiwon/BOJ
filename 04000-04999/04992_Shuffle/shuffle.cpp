#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

typedef	pair<int,int>	Shuffle;

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,r,d[MAX_SIZE];
		
		cin>>n>>r;
		
		if( n==0 && r==0 )
		{
			break;
		}
		
		for(int ptr=1,c=n;ptr<=n;ptr++,c--)
		{
			d[ptr] = c;
		}
		
		for(int i=1;i<=r;i++)
		{
			int	p,c,buf1[MAX_SIZE],buf2[MAX_SIZE];
			
			cin>>p>>c;
			
			for(int i=1;i<=p-1;i++)
			{
				buf1[i] = d[i];
			}
			
			for(int j=0;j<c;j++)
			{
				buf2[j+1] = d[p+j];
			}
			
			for(int i=1;i<=c;i++)
			{
				d[i] = buf2[i];
			}
			
			for(int i=1;i<=p-1;i++)
			{
				d[c+i] = buf1[i];
			}
		}
		
		cout<<d[1]<<'\n';
	}
	
	return	0;
}
