#include	<iostream>

using namespace	std;

int	main(void)
{
	int	S;
	
	cin>>S;
	cout<<S<<":\n";
	
	for(int first_row=2;first_row<=(S/2)+1;first_row++)
	{
		int	second_row;
		
		second_row = first_row-1;
		
		if( (S%(first_row+second_row)==0) || (S%(first_row+second_row)==first_row) )
		{
			cout<<first_row<<','<<second_row<<'\n';
		}
		
		if( S%first_row == 0 )
		{
			cout<<first_row<<','<<first_row<<'\n';
		}
	}
	
	return	0;
}
