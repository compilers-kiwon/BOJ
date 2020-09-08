#include	<iostream>

using namespace std;

#define	MAX_LEN_OF_DIGIT	(100+1)
#define	MOD(n)				((n)%1000000000)

typedef	unsigned long long	uint64;

uint64	table[MAX_LEN_OF_DIGIT][10];

int		main(void)
{
	int	N,i;
	
	cin>>N;
	
	for(i=1;i<=9;i++)
	{
		table[1][i] = 1;
	}
	
	for(i=2;i<=N;i++)
	{
		table[i][0] = table[i-1][1];
		
		for(int j=1;j<=8;j++)
		{
			table[i][j] = MOD(table[i-1][j-1]+table[i-1][j+1]);
		}
		
		table[i][9] = table[i-1][8];
	}
	
	uint64	answer;
	
	for(answer=0,i=0;i<=9;i++)
	{
		answer = answer+table[N][i];
	}
	cout<<MOD(answer)<<endl;
	
	return	0;
}
