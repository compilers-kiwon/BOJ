#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	DUMMY	'*'

int		get_len_of_square(int len)
{
	int	result;
	
	result = sqrt(len);
	
	if( result*result != len )
	{
		result++;
	}
	
	return	result;
}

void	init(string& str,int& square_len)
{
	cin>>str;
	
	square_len = get_len_of_square(str.length());
	
	for(int i=str.length();i<square_len*square_len;i++)
	{
		str.push_back(DUMMY);
	}
}

void	build_output(string& in,string& out,int square_len)
{
	for(int col=0;col<square_len;col++)
	{
		for(int row=square_len-1;row>=0;row--)
		{
			char&	c = in[row*square_len+col];
			
			if( c != DUMMY )
			{
				out.push_back(c);
			}
		}
	}
}

int		main(void)
{
	int	N;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	while(N>0)
	{
		string	original_message,secret_message;
		int		square_len;
		
		init(original_message,square_len);
		build_output(original_message,secret_message,square_len);
		
		cout<<secret_message<<'\n';
		
		N--;
	}
	
	return	0;
}
