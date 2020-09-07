#include	<iostream>

using namespace	std;

int	main(void)
{
	int	big,small,sum,diff;
	
	cin>>sum>>diff;
	
	if( (sum-diff)%2 == 0 )
	{
		small = (sum-diff)/2;
		big = small+diff;
		
		if( !(big>=small) || big<0 || small<0 )
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<big<<' '<<small<<endl;
		}
	}
	else
	{
		cout<<"-1\n";
	}
	
	return	0;
}
