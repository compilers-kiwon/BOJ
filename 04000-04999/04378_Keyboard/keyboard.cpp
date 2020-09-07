#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

typedef	pair<int,int>	RowCol;

map<char,RowCol>	key;

const char keyboard[5][14] = {
							 {'`','1','2','3','4','5','6','7','8','9','0','-','=','\b'},
							 {'\t','Q','W','E','R','T','Y','U','I','O','P','[',']','\\'},
							 {'A', 'S','D','F','G','H','J','K','L',';','\'','\n','\0','\0'},
							 {'Z', 'X','C','V','B','N','M',',','.','/','\0','\0','\0','\0'},
							 {'\0', '\0',' ','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
							};
							
void	init(void)
{
	int		i;
	char	c;
	
	for(i=1,c='1';i<=9;i++,c++)
	{
		key[c] = make_pair(0,i);
	}
	key['0'] = make_pair(0,10);
	key['-'] = make_pair(0,11);
	key['='] = make_pair(0,12);
	
	key['Q'] = make_pair(1,1);
	key['W'] = make_pair(1,2);
	key['E'] = make_pair(1,3);
	key['R'] = make_pair(1,4);
	key['T'] = make_pair(1,5);
	key['Y'] = make_pair(1,6);
	key['U'] = make_pair(1,7);
	key['I'] = make_pair(1,8);
	key['O'] = make_pair(1,9);
	key['P'] = make_pair(1,10);
	key['['] = make_pair(1,11);
	key[']'] = make_pair(1,12);
	key['\\'] = make_pair(1,13);
	
	key['A'] = make_pair(2,0);
	key['S'] = make_pair(2,1);
	key['D'] = make_pair(2,2);
	key['F'] = make_pair(2,3);
	key['G'] = make_pair(2,4);
	key['H'] = make_pair(2,5);
	key['J'] = make_pair(2,6);
	key['K'] = make_pair(2,7);
	key['L'] = make_pair(2,8);
	key[';'] = make_pair(2,9);
	key['\''] = make_pair(2,10);
	key['\n'] = make_pair(2,11);
	
	key['Z'] = make_pair(3,0);
	key['X'] = make_pair(3,1);
	key['C'] = make_pair(3,2);
	key['V'] = make_pair(3,3);
	key['B'] = make_pair(3,4);
	key['N'] = make_pair(3,5);
	key['M'] = make_pair(3,6);
	key[','] = make_pair(3,7);
	key['.'] = make_pair(3,8);
	key['/'] = make_pair(3,9);
	
	key[' '] = make_pair(4,2);
}

int		main(void)
{
	init();
	
	while(1)
	{
		string	str,t;
		
		getline(cin,str);
		
		if( str == "" )
		{
			break;
		}
		
		for(int i=0;i<str.length();i++)
		{
			int		row,col;
			char	c;
			
			if( str[i] == ' ' )
			{
				c = ' ';
			}
			else
			{
				row = key[str[i]].first;
				col = key[str[i]].second;
				
				c = keyboard[row][col-1];
			}
			
			t.push_back(c);
		}
		
		cout<<t<<endl;
	}
	return	0;
}
