#include	<iostream>
#include	<cstring>

using namespace	std;

#define	STR_MAX_LEN		(1000000+1)
#define	BOMB_MAX_LEN	(36+1)

char	str[STR_MAX_LEN+1],answer[STR_MAX_LEN+1],bomb[BOMB_MAX_LEN+1];
int		str_len,bomb_len;
int		answer_index;

int		main(void)
{
	char	bomb_last_char,c;
	
	scanf("%s %s",&str[1],&bomb[1]);
	
	answer_index = 0;
	str_len = strlen(&str[1]);
	bomb_len = strlen(&bomb[1]);
	bomb_last_char = bomb[bomb_len];
	
	for(int i=1;(c=str[i])!='\0';i++)
	{
		answer[++answer_index] = c;
		
		if( answer_index >= bomb_len && c == bomb_last_char )
		{
			bool	result = true;
			
			for(int a=answer_index-1,b=bomb_len-1;b>0;a--,b--)
			{
				if( answer[a] != bomb[b] )
				{
					result = false;
					break;
				}
			}
			
			if( result == true )
			{
				answer_index -= bomb_len;
			}
		}
	}
	
	if( answer_index != 0 )
	{
		answer[++answer_index] = '\0';
		puts(&answer[1]);
	}
	else
	{
		puts("FRULA");
	}
	
	return	0;
}
