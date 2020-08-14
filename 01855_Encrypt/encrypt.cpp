#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		num_of_col,num_of_row;
	string	encrypted,decrypted;
	
	cin>>num_of_col>>encrypted;
	num_of_row = encrypted.length()/num_of_col;
	
	for(int col=0;col<num_of_col;col++)
	{
		for(int row=0;row<num_of_row;row++)
		{
			if( row%2 == 0 )
			{
				decrypted.push_back(encrypted[row*num_of_col+col]);
			}
			else
			{
				decrypted.push_back(encrypted[row*num_of_col+(num_of_col-1-col)]);
			}
		}
	}
	
	cout<<decrypted<<'\n';
	
	return	0;
}
