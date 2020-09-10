#include	<iostream>

using namespace	std;

#define	MAX_LEN	10
#define	MAX_NUM	20

#define	TRUE	1
#define	FALSE	0

int	S[MAX_NUM+1];

int	main(void)
{
	char	inst[MAX_LEN];
	int		M,x;
	
	scanf("%d",&M);
	
	for(int i=1;i<=M;i++)
	{
		scanf("%s",inst);
		
		switch(inst[0])
		{
			case	'a':
				if( inst[1] == 'd' )
				{
					scanf("%d",&x);
					S[x] = TRUE;	
				}
				else
				{
					S[1] = S[2] = S[3] = S[4] = S[5] = S[6] = S[7] = S[8] = S[9] = S[10] =
					S[11] = S[12] = S[13] = S[14] = S[15] = S[16] = S[17] = S[18] = S[19] = S[20] = TRUE;
				}
				break;
			case	'r':
				scanf("%d",&x);
				S[x] = FALSE;
				break;
			case	'c':
				scanf("%d",&x);
				printf("%d\n",S[x]);
				break;
			case	't':
				scanf("%d",&x);
				S[x] ^= TRUE;
				break;
			case	'e':
				S[1] = S[2] = S[3] = S[4] = S[5] = S[6] = S[7] = S[8] = S[9] = S[10] =
				S[11] = S[12] = S[13] = S[14] = S[15] = S[16] = S[17] = S[18] = S[19] = S[20] = FALSE;
				break;
		}
	}
	return	0;
}
