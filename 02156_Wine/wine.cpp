#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_WINE	(10000+1)

vector<int>	wine(MAX_NUM_OF_WINE);
vector<int>	quantity_of_wine(MAX_NUM_OF_WINE,0);

int	main(void)
{
	int	n,i,max_wine;
	
	cin>>n;
	
	for(wine[0]=0,i=1;i<=n;i++)
	{
		cin>>wine[i];
	}
	
	quantity_of_wine[0] = 0;
	quantity_of_wine[1] = wine[1];
	quantity_of_wine[2] = wine[1]+wine[2];
	
	for(i=3;i<=n;i++)
	{
		quantity_of_wine[i] = max(quantity_of_wine[i-1],max(quantity_of_wine[i-3]+wine[i-1]+wine[i],quantity_of_wine[i-2]+wine[i]));
	}
	
	for(max_wine=0,i=1;i<=n;i++)
	{
		max_wine = max(max_wine,quantity_of_wine[i]);
	}
	
	cout<<max_wine<<endl;
	
	return	0;
}
