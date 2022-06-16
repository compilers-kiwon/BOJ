#include	<iostream>

using namespace	std;

#define	SIZE	9

int	main(void)
{
	int	max_n,max_row,max_col;
	
	max_n = -1;
	
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			int	n;
			
			cin>>n;
			
			if( n > max_n )
			{
				max_n = n;
				max_row = i,max_col = j;
			}
		}
	}
	cout<<max_n<<endl<<max_row<<' '<<max_col<<endl;
	
	return	0;
}
