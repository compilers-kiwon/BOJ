#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_ALPHABET		26
#define	GET_INDEX(c)		((int)((c)-'a'))
#define	MAX_NUM_OF_WORDS	4

int		get_distance(char from,char to)
{
	int	f,t,d;
	
	f = GET_INDEX(from);
	t = GET_INDEX(to);
	
	d = t-f;
	
	if( d < 0 )
	{
		d += NUM_OF_ALPHABET;
	}
	
	return	d;
}

void	get_words(string& str,string* words)
{
	str.push_back(' ');
	
	for(int i=0,w_index=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			w_index++;
		}
		else
		{
			words[w_index].push_back(c);
		}
	}
}

int	main(void)
{
	string	alphabet;
	
	for(int i=0;i<NUM_OF_ALPHABET;i++)
	{
		alphabet.push_back((char)((int)'a'+i));
	}
	
	for(;;)
	{
		string	str,w[MAX_NUM_OF_WORDS];
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		get_words(str,w);
		
		for(int i=0;i<w[0].length();i++)
		{
			int	d,index;
			
			d = get_distance(w[0][i],w[1][i]);
			index = (GET_INDEX(w[2][i])+d)%NUM_OF_ALPHABET;
			
			w[3].push_back(alphabet[index]);
		}
		
		cout<<w[0]<<' '<<w[1]<<' '<<w[2]<<' '<<w[3]<<'\n';
	}
	
	return	0;	
}
