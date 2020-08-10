#include	<iostream>

using namespace	std;

#define	MAX_E	15
#define	MAX_S	28
#define	MAX_M	19

int	main(void)
{
	int	E,S,M,e,s,m;
	int	cycle,i;
	
	cin>>E>>S>>M;
	
	if( E==1 && S==1 && M==1 )
	{
		cout<<"1\n";
		return	0;
	}
	
	cycle = MAX_E*MAX_S*MAX_M;
	
	for(i=1,e=s=m=0;i<=cycle;i++)
	{
		e = (e+1)%MAX_E;
		s = (s+1)%MAX_S;
		m = (m+1)%MAX_M;
		
		if( e+1==E && s+1==S && m+1==M )
		{
			break;
		}
	}
	cout<<i+1<<endl;
	
	return	0;
}

