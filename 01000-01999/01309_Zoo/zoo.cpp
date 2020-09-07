#include	<iostream>

using namespace	std;

#define	MOD_NUM	9901
#define	MOD(n)	((n)%MOD_NUM)

#define	STATE_XX	0
#define	STATE_OX	1
#define	STATE_XO	2
#define	MAX_STATE	3

#define	MAX_SIZE	(100000+1)

int	cage[MAX_SIZE][MAX_STATE];

int	main(void)
{
	int	N;
	
	cin>>N;
	
	cage[1][STATE_XX] = cage[1][STATE_OX] = cage[1][STATE_XO] = 1;
	
	for(int i=2;i<=N;i++)
	{
		cage[i][STATE_XX] = MOD(cage[i-1][STATE_XX]+cage[i-1][STATE_OX]+cage[i-1][STATE_XO]);
		cage[i][STATE_OX] = MOD(cage[i-1][STATE_XX]+cage[i-1][STATE_XO]);
		cage[i][STATE_XO] = MOD(cage[i-1][STATE_XX]+cage[i-1][STATE_OX]);
	}
	
	cout<<MOD(cage[N][STATE_XX]+cage[N][STATE_OX]+cage[N][STATE_XO])<<endl;
	
	return	0;
}
