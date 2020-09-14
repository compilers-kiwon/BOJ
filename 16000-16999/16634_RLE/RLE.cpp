#include	<iostream>
#include	<string>

using namespace	std;

#define	int2char(i)	((char)((i)+(int)'0'))
#define	char2int(c)	((int)((c)-'0'))

void	decoding(string& src,string& decode_str)
{
	for(int i=0;i<src.length();i+=2)
	{
		char&	c = src[i+0];
		char&	n = src[i+1];
		
		for(int j=char2int(n);j>=1;j--)
		{
			decode_str.push_back(c);
		}
	}
}

void	encoding(string& src,string& encode_str)
{
	char	prev;
	int		cnt,i;
	
	for(prev=src[0],cnt=1,i=1;i<src.length();i++)
	{
		char&	current = src[i];
		
		if( prev == current )
		{
			cnt++;
		}
		else
		{
			encode_str.push_back(prev);
			encode_str.push_back(int2char(cnt));
			
			cnt = 1;
			prev = current;	
		}	
	}
}

int		main(void)
{
	char	c;
	string	str,result;
	
	cin>>c>>str;
	str.push_back(' ');
	
	if( c == 'E' )
	{
		encoding(str,result);
	}
	else
	{
		decoding(str,result);
	}
	
	cout<<result<<'\n';
	
	return	0;
}
