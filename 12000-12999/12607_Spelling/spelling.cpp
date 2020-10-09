#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<char,string>	keypress;

#define	tail(s)	((s)[(s).length()-1])
#define	head(s)	((s)[0])

void	init(void)
{
	keypress['a'] = "2";
	keypress['b'] = "22";
	keypress['c'] = "222";
	
	keypress['d'] = "3";
	keypress['e'] = "33";
	keypress['f'] = "333";
	
	keypress['g'] = "4";
	keypress['h'] = "44";
	keypress['i'] = "444";
	
	keypress['j'] = "5";
	keypress['k'] = "55";
	keypress['l'] = "555";
	
	keypress['m'] = "6";
	keypress['n'] = "66";
	keypress['o'] = "666";
	
	keypress['p'] = "7";
	keypress['q'] = "77";
	keypress['r'] = "777";
	keypress['s'] = "7777";
	
	keypress['t'] = "8";
	keypress['u'] = "88";
	keypress['v'] = "888";
	
	keypress['w'] = "9";
	keypress['x'] = "99";
	keypress['y'] = "999";
	keypress['z'] = "9999";
	
	keypress[' '] = "0";
}

int		main(void)
{
	int	N;
	
	init();
	cin>>N;getchar();
	
	for(int n=1;n<=N;n++)
	{
		string	str,out;
		
		getline(cin,str);
			
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			
			if( !out.empty() && tail(out)==head(keypress[c]) )
			{
				out.push_back(' ');
			}
			
			out += keypress[c];
		}
		
		cout<<"Case #"<<n<<": "<<out<<'\n';
	}
	
	return	0;
}
