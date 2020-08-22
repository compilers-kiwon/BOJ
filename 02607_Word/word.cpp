#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	NUM_OF_CHARS	26
#define	GET_INDEX(c)	((int)((c)-'A'))
#define	ABS(n)			((n)<0?-(n):(n))

vector<int>	num_of_src_char(NUM_OF_CHARS,0);
vector<int> num_of_dst_char(NUM_OF_CHARS);

int	main(void)
{
	int		N,cnt,src_len;
	string	word;
	
	cin>>N;
	cin>>word;
	src_len = word.length();
	
	for(int i=0;i<src_len;i++)
	{
		++num_of_src_char[GET_INDEX(word[i])];
	}
	
	cnt = 0;
	
	for(int i=2;i<=N;i++)
	{
		int	dst_len;
		
		cin>>word;
		dst_len = word.length();
		
		for(int j=0;j<NUM_OF_CHARS;j++)
		{
			num_of_dst_char[j] = 0;
		}
		
		for(int j=0;j<dst_len;j++)
		{
			++num_of_dst_char[GET_INDEX(word[j])];
		}
		
		int	num_of_char_in_src_only,num_of_char_in_dst_only;
		
		num_of_char_in_src_only = num_of_char_in_dst_only = 0;
		
		for(int j=0;j<NUM_OF_CHARS;j++)
		{
			int diff = num_of_src_char[j]-num_of_dst_char[j];
			
			if( diff > 0 )
			{
				num_of_char_in_src_only = num_of_char_in_src_only+diff;
			}
			else if( diff < 0 )
			{
				num_of_char_in_dst_only = num_of_char_in_dst_only+(-diff);
			}
		}
		
		if( src_len == dst_len )
		{
			if( (num_of_char_in_src_only == 1 && num_of_char_in_dst_only == 1)
				|| (num_of_char_in_src_only == 0 && num_of_char_in_dst_only == 0) )
			{
				++cnt;
			}
		}
		else if( src_len+1 == dst_len )
		{
			if( num_of_char_in_src_only == 0 && num_of_char_in_dst_only == 1 )
			{
				++cnt;
			}
		}
		else if( src_len == dst_len+1 )
		{
			if( num_of_char_in_src_only == 1 && num_of_char_in_dst_only == 0 )
			{
				++cnt;
			}
		}		
	}
	cout<<cnt<<endl;
}
