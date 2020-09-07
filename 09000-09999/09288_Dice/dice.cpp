#include	<iostream>

using namespace	std;

#define	DICE_SIZE			6
#define	IN_RANGE(MIN,n,MAX)	(MIN<=(n)&&(n)<=MAX)

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int		sum;
		bool	sum_table[DICE_SIZE+1][DICE_SIZE+1];
		
		fill_n(&sum_table[0][0],(DICE_SIZE+1)*(DICE_SIZE+1),false);
		
		cin>>sum;
		cout<<"Case "<<t<<":\n";
		
		for(int d1=1;d1<=6;d1++)
		{
			int d2;
			
			d2 = sum-d1;
			
			if( IN_RANGE(1,d2,DICE_SIZE) && sum_table[d1][d2]==false )
			{
				cout<<'('<<d1<<','<<d2<<")\n";
				sum_table[d1][d2] = sum_table[d2][d1] = true;
			}
		}
	}
	
	return	0;
}
