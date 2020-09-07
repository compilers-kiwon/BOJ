#include	<iostream>
#include	<string>

using namespace	std;

void	get_len_of_row_and_col(int len,int& row,int& col)
{
	for(int R=1;;R++)
	{
		int	C;
		
		if( len%R != 0 )
		{
			continue;
		}
		
		C = len/R;
		
		if( R<=C )
		{
			row = R;
			col = C;
		}
		else
		{
			break;
		}
	}
}

void	print_decrypted_mail(string& mail,int num_of_row,int num_of_col)
{
	for(int i=0;i<num_of_row;i++)
	{
		for(int j=0;j<num_of_col;j++)
		{
			cout<<mail[i+num_of_row*j];
		}
	}
	cout<<endl;
}

int		main(void)
{
	string	encrypted_mail;
	int		R,C;
	
	cin>>encrypted_mail;
	
	get_len_of_row_and_col(encrypted_mail.length(),R,C);
	print_decrypted_mail(encrypted_mail,R,C);
	
	return	0;
}
