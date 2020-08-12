#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_LEN_OF_PW	(15+1)
#define	MAX_NUM_OF_CHAR	(15+1)

char	password[MAX_LEN_OF_PW+1];
char	usable_chars[MAX_NUM_OF_CHAR];
int		L,C;

int		get_num_of_vowel(void)
{
	int	cnt,i;
	
	for(cnt=0,i=1;i<=L;i++)
	{
		switch(password[i])
		{
			case	'a':
			case	'e':
			case	'i':
			case	'o':
			case	'u':
				++cnt;
			default	   :
				break;
		}
	}
	return	cnt;
}

void	build_password(int index,int prev_used_char_index)
{
	if( index > L )
	{
		int	num_of_vowel;
		
		num_of_vowel = get_num_of_vowel();
		
		if( num_of_vowel >= 1 && L-num_of_vowel >=2 )
		{
			printf("%s\n",&password[1]);
		}
		return;
	}
	
	int	to = C-(L-index);
	
	for(int i=prev_used_char_index+1;i<=to;i++)
	{
		password[index] = usable_chars[i];
		build_password(index+1,i);
	}
}

int		main(void)
{
	scanf("%d %d",&L,&C);
	getchar();
	
	for(int i=1;i<=C;i++)
	{
		scanf("%c",&usable_chars[i]);
		getchar();
	}
	sort(&usable_chars[1],&usable_chars[C+1]);
	
	password[L+1] = '\0';
	
	build_password(1,0);
	
	return	0;
}
