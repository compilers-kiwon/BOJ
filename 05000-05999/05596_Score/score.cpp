#include	<iostream>

using namespace	std;

#define	NUM_OF_SUBJECT	4

int	main(void)
{
	int	sum1,sum2,i;
	
	for(sum1=0,i=1;i<=NUM_OF_SUBJECT;i++)
	{
		int	n;
		
		cin>>n;
		sum1 += n;	
	}
	
	for(sum2=0,i=1;i<=NUM_OF_SUBJECT;i++)
	{
		int	n;
		
		cin>>n;
		sum2 += n;	
	}
	
	if( sum1 < sum2 )
	{
		cout<<sum2<<endl;
	}
	else
	{
		cout<<sum1<<endl;
	}
	
	return	0;
}
