#include	<iostream>
#include	<string>

using namespace	std;

#define	HH	0
#define	MM	1
#define	SS	2

#define	BIT_LEN	6

void	convert_bit(int n,int* bit)
{
	for(int i=BIT_LEN-1;i>=0;i--)
	{
		bit[i] = n&0x1;
		n >>= 1;
	}
}

int		main(void)
{
	int	N;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	while(N>0)
	{
		string	time;
		int		h,m,s;
		
		cin>>time;
		time[2] = time[5] = ' ';
		sscanf(time.c_str(),"%d %d %d",&h,&m,&s);
		
		int	led[SS+1][BIT_LEN];
		
		convert_bit(h,led[HH]);
		convert_bit(m,led[MM]);
		convert_bit(s,led[SS]);
		
		for(int i=0;i<BIT_LEN;i++)
		{
			for(int j=HH;j<=SS;j++)
			{
				cout<<led[j][i];
			}
		}
		
		cout<<' ';
		
		for(int i=HH;i<=SS;i++)
		{
			for(int j=0;j<BIT_LEN;j++)
			{
				cout<<led[i][j];
			}
		}
		
		cout<<'\n';
		
		N--;
	}
	
	return	0;
}
