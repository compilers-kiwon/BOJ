#include	<iostream>

using namespace std;

typedef	unsigned int	uint32;

int		main(void)
{
	while( true )
	{
		uint32	n,k,i,result;
		
		cin>>n>>k;
		
		if( n == 0 && k == 0 )
		{
			break;
        }
		
        if( k > (n-k) )
        {
        	k = n-k;
		}
		
		for(result=1,i=1;i<=k;i++)
		{
			result = result*n;
			--n;
			result = result/i;
		}
		
		cout<<result<<endl;
	}
	return	0;
}
