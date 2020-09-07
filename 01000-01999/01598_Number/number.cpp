#include	<iostream>
#include	<cmath>

using namespace	std;

#define	LEN	4

#define	GET_ROW(n)	(((n)-1)%LEN)
#define	GET_COL(n)	(((n)-1)/LEN)

int	main(void)
{
	int	n1,n2,n1_row,n1_col,n2_row,n2_col;
	
	cin>>n1>>n2;
	
	n1_row = GET_ROW(n1);
	n1_col = GET_COL(n1);
	
	n2_row = GET_ROW(n2);
	n2_col = GET_COL(n2);
	
	cout<<abs(n1_row-n2_row)+abs(n1_col-n2_col)<<endl;
	
	return	0;
}
