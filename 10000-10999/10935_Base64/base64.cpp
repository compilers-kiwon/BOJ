#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<int,string>		hex2str;
map<string,char>	base64;

void	init(void)
{
	hex2str[0] = "0000";
	hex2str[1] = "0001";
	hex2str[2] = "0010";
	hex2str[3] = "0011";
	hex2str[4] = "0100";
	hex2str[5] = "0101";
	hex2str[6] = "0110";
	hex2str[7] = "0111";
	hex2str[8] = "1000";
	hex2str[9] = "1001";
	hex2str[10] = "1010";
	hex2str[11] = "1011";
	hex2str[12] = "1100";
	hex2str[13] = "1101";
	hex2str[14] = "1110";
	hex2str[15] = "1111";
	
	for(int i=0;i<=25;i++)
	{
		char 	c = 'A'+(char)(i-0);
		string	s;
		
		s = hex2str[(i&0xf0)>>4]+hex2str[(i&0x0f)];
		base64[s.substr(2,6)] = c;
	}
	
	for(int i=26;i<=51;i++)
	{
		char 	c = 'a'+(char)(i-26);
		string	s;
		
		s = hex2str[(i&0xf0)>>4]+hex2str[(i&0x0f)];
		base64[s.substr(2,6)] = c;
	}
	
	for(int i=52;i<=61;i++)
	{
		char 	c = '0'+(char)(i-52);
		string	s;
		
		s = hex2str[(i&0xf0)>>4]+hex2str[(i&0x0f)];
		base64[s.substr(2,6)] = c;
	}
	
	base64["111110"] = '+';
	base64["111111"] = '/';
}

int		main(void)
{
	string	s,bin,b64;
	
	init();
	cin>>s;
	
	for(int i=0;i<s.length();i++)
	{
		int	a,b;
		
		a = (s[i]&0xf0)>>4;
		b = (s[i]&0x0f)>>0;
		
		bin += hex2str[a]+hex2str[b];
	}

	if( bin.length()%6 != 0 )
	{
		for(int i=0,to=6-(bin.length()%6);i<to;i++)
		{
			bin.push_back('0');
		}
	}
	
	for(int i=0;i<bin.length();i+=6)
	{
		b64.push_back(base64[bin.substr(i,6)]);
	}
	
	if( b64.length()%4 != 0 )
	{
		for(int i=0,to=4-(b64.length()%4);i<to;i++)
		{
			b64.push_back('=');
		}
	}
	
	cout<<b64<<'\n';
	
	return	0;
}
