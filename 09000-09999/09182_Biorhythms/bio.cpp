#include	<iostream>

using namespace	std;

#define	MAX_DAYS		21252
#define	PHYSICAL		23
#define	EMOTINAL		28
#define	INTELLECTUAL	33

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int c=1;;c++)
	{
		int	p,e,i,d;
		
		cin>>p>>e>>i>>d;
		
		if( p==-1 && e==-1 && i==-1 && d==-1 )
		{
			break;
		}
		
		for(int n=d+1;n<=MAX_DAYS;n++)
		{
			if( (n-p)%PHYSICAL==0 && (n-e)%EMOTINAL==0 && (n-i)%INTELLECTUAL==0 )
			{
				cout<<"Case "<<c<<": the next triple peak occurs in "<<n-d<<" days.\n";
				break;
			}
		}
	}
	
	return	0;
}
