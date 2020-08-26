#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	NUMBERS	10
#define	N		(NUMBERS-3)

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n[NUMBERS];
		
		for(int i=0;i<NUMBERS;i++)
		{
			cin>>n[i];
		}
		sort(&n[0],&n[NUMBERS]);
		cout<<n[N]<<endl;
		
		T--;
	}
	return	0;
}
