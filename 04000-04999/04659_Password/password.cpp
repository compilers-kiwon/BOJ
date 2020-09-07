#include	<iostream>
#include	<string>

using namespace	std;

#define	is_vowel(c)	((c)=='a'||(c)=='e'||(c)=='i'||(c)=='o'||(c)=='u')

int	main(void)
{
	while(1)
	{
		string	pw;
		
		cin>>pw;
		
		if( pw == "end" )
		{
			break;
		}
		
		bool	is_acceptable,vowel_found;
		char	prev;
				
		is_acceptable = true;
		vowel_found = false;
		prev = '\0';
	
		for(int i=0,cont_vowel_cnt=0,cont_consonant_cnt=0;i<pw.length()&&is_acceptable==true;i++)
		{
			char&	c = pw[i];
			
			if( is_vowel(c) == true )
			{
				vowel_found = true;
				cont_vowel_cnt++;
				cont_consonant_cnt = 0;
			}
			else
			{
				cont_vowel_cnt = 0;
				cont_consonant_cnt++;
			}
			
			if( cont_vowel_cnt ==3 || cont_consonant_cnt == 3 )
			{
				is_acceptable = false;
				break;
			}
			
			if( c!='e' && c!='o' )
			{
				if( prev == c )
				{
					is_acceptable = false;
					break;
				}
			}
			
			prev = c;
		}
		
		if( is_acceptable == true && vowel_found == true )
		{
			cout<<'<'<<pw<<"> is acceptable.\n";
		}
		else
		{
			cout<<'<'<<pw<<"> is not acceptable.\n";
		}		
	}
	
	return	0;
}
