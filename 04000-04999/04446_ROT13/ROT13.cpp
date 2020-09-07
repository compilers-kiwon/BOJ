#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	SIZE_OF_VOWEL_TABLE		6
#define	SIZE_OF_CONSONANT_TABLE	20

#define	GET_ADJ_VOWEL_INDEX(i)		(((i)+3)%SIZE_OF_VOWEL_TABLE)
#define	GET_ADJ_CONSONANT_INDEX(i)	(((i)+10)%SIZE_OF_CONSONANT_TABLE)

#define	LOWER_VOWEL			0
#define	UPPER_VOWEL			1
#define	LOWER_CONS			2
#define	UPPER_CONS			3
#define	MAX_NUM_OF_TABLE	4

string	table[MAX_NUM_OF_TABLE];

int		get_index(char c,int& table_index)
{
	int		result,t;
	bool	found;
	
	for(found=false,t=LOWER_VOWEL;t<=UPPER_CONS&&found==false;t++)
	{
		for(int i=0;i<table[t].length()&&found==false;i++)
		{
			if( c == table[t][i] )
			{
				found = true;
				table_index = t;
				result = i;
			}
		}
	}
	
	return	result;
}

int		main(void)
{	
	table[LOWER_VOWEL] = "aiyeou";
	table[UPPER_VOWEL] = "AIYEOU";
	table[LOWER_CONS] = "bkxznhdcwgpvjqtsrlmf";
	table[UPPER_CONS] = "BKXZNHDCWGPVJQTSRLMF";
	

	string	ROT13,origin;
	char	c;
	
	while( scanf("%c",&c) != EOF )
	{
		ROT13.push_back(c);
	}
		
	for(int i=0;i<ROT13.length();i++)
	{
		char&	c = ROT13[i];
		
		if( IN_RANGE('a',c,'z') || IN_RANGE('A',c,'Z') )
		{
			int		table_index,char_index;
			char	t;
			
			char_index = get_index(c,table_index);
			
			if( table_index == LOWER_VOWEL || table_index == UPPER_VOWEL )
			{
				t = table[table_index][GET_ADJ_VOWEL_INDEX(char_index)];
			}
			else
			{
				t = table[table_index][GET_ADJ_CONSONANT_INDEX(char_index)];
			}
			
			origin.push_back(t);
		}
		else
		{
			origin.push_back(c);
		}
	}
	
	cout<<origin;

	return	0;
}
