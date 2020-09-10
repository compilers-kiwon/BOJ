#include	<iostream>
#include	<string>

using namespace	std;

int	get_s_points(string& code,string& guess)
{
	int	c_table[0x100],g_table[0x100],ret;
	
	for(char c='A';c<='Z';c++)
	{
		c_table[c] = g_table[c] = 0;
	}
	
	for(int i=0;i<code.length();i++)
	{
		c_table[code[i]]++;
		g_table[guess[i]]++;
	}
	
	ret = 0;
	
	for(char c='A';c<='Z';c++)
	{
		ret += min(c_table[c],g_table[c]);
	}
	
	return	ret;
}

int	 get_r_points(string& code,string& guess,int& s)
{
	int	ret,i;
	
	for(ret=i=0;i<code.length();i++)
	{
		if( code[i] == guess[i] )
		{
			ret++;
			s--;
		}
	}
	
	return	ret;
}

int	main(void)
{
	int		N,s,r;
	string	c,g;
	
	cin>>N>>c>>g;
	
	s = get_s_points(c,g);
	r = get_r_points(c,g,s);
	
	cout<<r<<' '<<s<<'\n';
	
	return	0;
}
