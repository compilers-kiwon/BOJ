#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

void	init(map<char,string>& key_input,char* key_map,string& word)
{
	key_input['a'] = "2";
	key_input['b'] = "22";
	key_input['c'] = "222";
	key_input['d'] = "3";
	key_input['e'] = "33";
	key_input['f'] = "333";
	key_input['g'] = "4";
	key_input['h'] = "44";
	key_input['i'] = "444";
	key_input['j'] = "5";
	key_input['k'] = "55";
	key_input['l'] = "555";
	key_input['m'] = "6";
	key_input['n'] = "66";
	key_input['o'] = "666";
	key_input['p'] = "7";
	key_input['q'] = "77";
	key_input['r'] = "777";
	key_input['s'] = "7777";
	key_input['t'] = "8";
	key_input['u'] = "88";
	key_input['v'] = "888";
	key_input['w'] = "9";
	key_input['x'] = "99";
	key_input['y'] = "999";
	key_input['z'] = "9999";
	
	for(char i='1';i<='9';i++)
	{
		int	n;
		
		cin>>n;
		key_map[n] = i;
	}
	
	cin>>word;
}

int		main(void)
{
	map<char,string>	key_input;
	char 				key_map[9+1];
	string 				word,touch;
	
	init(key_input,key_map,word);
	
	for(int i=0;i<word.length();i++)
	{
		string&	in = key_input[word[i]];
		int		key_number = char2int(in[0]);
		int		key_len = in.length();
		char	actual_key = key_map[key_number];
		
		if( *(touch.end()-1) == actual_key )
		{
			touch.push_back('#');
		}
		
		for(int j=1;j<=key_len;j++)
		{
			touch.push_back(actual_key);
		}
	}
	cout<<touch<<endl;
	
	return	0;
}
