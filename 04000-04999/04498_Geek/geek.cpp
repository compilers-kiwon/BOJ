#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<string,int>	bin2dec;
map<int,string>	dec2bin;

#define	MAX_NUM	0x8FFF

void	bin2str(int n,string& str)
{
	for(;n>0;n/=2)
	{
		if( n%2 == 1 )
		{
			str.push_back('1');
		}
		else
		{
			str.push_back('0');
		}
	}
	
	for(int h=0,t=str.length()-1;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
}

int	bin2dec_func(string& bin)
{
	int	b,i,ret;
	
	for(ret=i=0,b=1;i<bin.length();i++)
	{
		char&	c = bin[i];
		
		if( c == '1' )
		{
			ret = ret*(-2)+1;
		}
		else
		{
			ret *= -2;
		}
	}
	
	return	ret;
}

void	init(void)
{
	bin2dec["0"] = 0;
	dec2bin[0] = "0";
	
	for(int n=1;n<MAX_NUM;n++)
	{
		string	bin_num;
		int		dec;
		
		bin2str(n,bin_num);
		dec = bin2dec_func(bin_num);
		
		bin2dec[bin_num] = dec;
		dec2bin[dec] = bin_num;
	}
}

int		main(void)
{
	int	t;
	
	cin>>t;
	init();
	
	for(int i=1;i<=t;i++)
	{
		char	b;
		string	bin;
		int		dec;
		
		cin>>b;
		
		if( b == 'b' )
		{
			cin>>bin;
			
			string	s;
			int		h;
			
			for(h=0;h<bin.length()-2&&bin[h]=='0';h++);
			
			s = bin.substr(h,bin.length()-h);
			cout<<"From binary: "<<bin<<" is "<<bin2dec[s]<<'\n';
		}
		else
		{
			cin>>dec;
			cout<<"From decimal: "<<dec<<" is "<<dec2bin[dec]<<'\n';
		}
	}
	
	return	0;
}
