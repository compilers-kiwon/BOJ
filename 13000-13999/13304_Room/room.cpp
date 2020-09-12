#include	<iostream>

using namespace	std;

#define	GIRL	0
#define	BOY		1
#define	MAX_SEX	2

#define	MAX_CLASS	6

int	main(void)
{
	int	student[MAX_CLASS+1][MAX_SEX];
	int	N,K,room,tmp;
	
	for(int i=1;i<=MAX_CLASS;i++)
	{
		for(int j=GIRL;j<=BOY;j++)
		{
			student[i][j] = 0;
		}
	}
	
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		int	S,Y;
		
		scanf("%d %d",&S,&Y);
		student[Y][S]++;
	}
	
	room = 0;
	
	tmp = student[1][BOY]+student[1][GIRL]+student[2][BOY]+student[2][GIRL];
	room += tmp/K+((tmp%K)?1:0);
	
	tmp = student[3][BOY]+student[4][BOY];
	room += tmp/K+((tmp%K)?1:0);
	
	tmp = student[3][GIRL]+student[4][GIRL];
	room += tmp/K+((tmp%K)?1:0);
	
	tmp = student[5][BOY]+student[6][BOY];
	room += tmp/K+((tmp%K)?1:0);
	
	tmp = student[5][GIRL]+student[6][GIRL];
	room += tmp/K+((tmp%K)?1:0);
	
	printf("%d\n",room);
	
	return	0;
}
