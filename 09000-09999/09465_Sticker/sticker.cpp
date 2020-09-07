#include	<iostream>

using namespace std;

#define	MAX_SIZE	(100000+1)

int	sticker[2][MAX_SIZE];
int	value[2][MAX_SIZE];

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n;
		
		cin>>n;
		
		for(int i=0;i<2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>sticker[i][j];
			}
		}
		sticker[0][0] = sticker[1][0] = 0;
		
		value[0][0] = sticker[0][0];
		value[1][0] = sticker[1][0];
		value[0][1] = sticker[0][1];
		value[1][1] = sticker[1][1];
		
		for(int i=2;i<=n;i++)
		{
			value[0][i] = sticker[0][i]+max(value[1][i-1],value[1][i-2]);
			value[1][i] = sticker[1][i]+max(value[0][i-1],value[0][i-2]);
		}
		cout<<max(value[0][n],value[1][n])<<endl;
		T--;
	}
	return	0;
}
