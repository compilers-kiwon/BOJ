#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	str;
	int		joi_cnt,ioi_cnt;
	
	cin>>str;
	joi_cnt = ioi_cnt = 0;
	
	for(int i=0;i<str.length()-2;i++)
	{
		if( str[i] == 'J' )
		{
			if( str[i+1] == 'O' && str[i+2] == 'I' )
			{
				++joi_cnt;
			}
		}
		else if( str[i] == 'I' )
		{
			if( str[i+1] == 'O' && str[i+2] == 'I' )
			{
				++ioi_cnt;
			}
		}
	}
	cout<<joi_cnt<<endl<<ioi_cnt<<endl;
	
	return	0;
}
