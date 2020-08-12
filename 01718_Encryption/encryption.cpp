#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_CHARS	26

#define	CHAR2INT(c)		((int)((c)-'a'))
#define	GET_DIFF(n)		(NUM_OF_CHARS-(n))

int	main(void)
{
	string	key,plain,encryption;
	char	alphabet[NUM_OF_CHARS],c;
	int		i;
	
	for(i=0,c='a';i<NUM_OF_CHARS;i++,c++)
	{
		alphabet[i] = c;
	}
	
	getline(cin,plain);
	cin>>key;
	
	for(int i=0;i<plain.length();i++)
	{
		int key_index,diff;
		
		if( plain[i] == ' ' )
		{
			encryption.push_back(' ');
			continue;
		}
		
		key_index = i%key.length();
		diff = GET_DIFF(CHAR2INT(key[key_index]));
		c = alphabet[(CHAR2INT(plain[i])+diff-1)%NUM_OF_CHARS];
		encryption.push_back(c);
	}
	cout<<encryption<<endl;
	
	return	0;
}
