#include	<iostream>

using namespace	std;

#define	SPACE		' '
#define	PERIOD		'.'
#define	MAX_SIZE	0x100
#define	MAX_LEN		(1000+1)

int		N,encrypted[MAX_LEN];
bool	possible_to_be_non_alphabet[MAX_SIZE];

void	init(void)
{
	for(char c='0';c<='9';c++)
	{
		possible_to_be_non_alphabet[c^SPACE]
		= possible_to_be_non_alphabet[c^PERIOD] = true;
	}
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%x",&encrypted[i]);
	}
}

int		main(void)
{
	init();
	
	for(int i=1;i<=N;i++)
	{
		if( possible_to_be_non_alphabet[encrypted[i]] == true )
		{
			putchar('.');
		}
		else
		{
			putchar('-');
		}
	}
	puts("");
	
	return	0;
}
