#include	<iostream>

using namespace	std;

#define	MAX_NUM	300

int	main(void)
{
	int	T[MAX_NUM+2],i,t;
	
	for(i=1,T[0]=0;i<=MAX_NUM+1;i++)
	{
		T[i] = T[i-1]+i;
	}
	
	cin>>t;
	
	while(t>0)
	{
		int	n,W;
		
		cin>>n;
		
		for(i=1,W=0;i<=n;i++)
		{
			W += i*T[i+1];
		}
		cout<<W<<endl;
		
		t--;
	}
	return	0;
}
