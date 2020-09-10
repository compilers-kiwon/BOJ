#include	<iostream>

using namespace std;

#define	MAX_SIZE			(1000+1)

int	tile[MAX_SIZE];

int	main(void)
{
	int	n;
	
	tile[1] = 1;
	tile[2] = 3;
	
	cin>>n;
	
	for(int i=3;i<=n;i++)
	{
		tile[i] = (tile[i-1]+2*tile[i-2])%10007;
	}
	cout<<tile[n]<<endl;
	
	return	0;
}
