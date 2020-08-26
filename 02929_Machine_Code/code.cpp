#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	int		index_1,index_2,cnt;
	string	op;
	
	cin>>op;
	
	for(index_1 = index_2 = cnt =0;index_1<op.length();index_1++)
	{
		char&	c = op[index_1];
		
		if( IN_RANGE('A',c,'Z') )
		{
			if( index_2%4 != 0 )
			{
				for(;index_2%4!=0;index_2++,cnt++);
			}
		}
		index_2++;
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
