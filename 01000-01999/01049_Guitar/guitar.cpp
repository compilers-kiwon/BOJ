#include	<iostream>
#include	<queue>

using namespace	std;

#define	NUM_OF_PIECES_IN_PACKAGE	6

int	main(void)
{
	int	N,M,min_cost;
	int	min_price_of_package,min_price_of_piece;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	min_price_of_package = min_price_of_piece = 0x7FFFFFF;
	
	for(int i=1;i<=M;i++)
	{
		int	package,piece;
		
		cin>>package>>piece;
		
		min_price_of_package = min(min_price_of_package,min(package,NUM_OF_PIECES_IN_PACKAGE*piece));
		min_price_of_piece = min(min_price_of_piece,min(package,piece));
	}
	
	int	tmp1,tmp2;
	
	tmp1 = N/NUM_OF_PIECES_IN_PACKAGE*min_price_of_package+(N%NUM_OF_PIECES_IN_PACKAGE)*min_price_of_piece;
	tmp2 = N/NUM_OF_PIECES_IN_PACKAGE*min_price_of_package+(((N%NUM_OF_PIECES_IN_PACKAGE)==0)?0:min_price_of_package);
	
	min_cost = min(tmp1,tmp2);
	
	cout<<min_cost<<'\n';
	
	return	0;
}
