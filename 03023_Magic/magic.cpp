#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	char	card[MAX_SIZE][MAX_SIZE];
	int		R,C,A,B;
	
	cin>>R>>C;
	
	for(int i=1;i<=R;i++)
	{
		scanf("%s",&card[i][1]);
	}
	
	cin>>A>>B;
	
	for(int i=1;i<=R;i++)
	{
		for(int head=1,tail=2*C;head<=C;head++,tail--)
		{
			card[i][tail] = card[i][head];
		}
		card[i][2*C+1] = '\0';
	}
	
	for(int head=1,tail=2*R;head<=R;head++,tail--)
	{
		for(int j=1;j<=2*C+1;j++)
		{
			card[tail][j] = card[head][j];
		}
	}
	
	if( card[A][B] == '#' )
	{
		card[A][B] = '.';
	}
	else
	{
		card[A][B] = '#';
	}
	
	for(int i=1;i<=2*R;i++)
	{
		puts(&card[i][1]);
	}
	
	return	0;
}
