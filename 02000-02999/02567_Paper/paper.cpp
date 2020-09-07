#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100
#define	COLOR_LEN	10

int	main(void)
{
	bool	paper[MAX_SIZE+2][MAX_SIZE+2];
	
	for(int row=0;row<=MAX_SIZE+1;row++)
	{
		for(int col=0;col<=MAX_SIZE;col++)
		{
			paper[row][col] = false;
		}
	}
	
	int	p;
	
	cin>>p;
	
	while(p>0)
	{
		int	row,col,to_row,to_col;
		
		cin>>row>>col;
		to_row = row+COLOR_LEN;
		to_col = col+COLOR_LEN;
		
		for(int i=row;i<to_row;i++)
		{
			for(int j=col;j<to_col;j++)
			{
				paper[i][j] = true;
			}
		}
		
		p--;
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		for(int j=1;j<=MAX_SIZE;j++)
		{
			if( paper[i][j] == true )
			{
				cnt += (paper[i-1][j] == false)+(paper[i+1][j]==false)+(paper[i][j-1] == false)+(paper[i][j+1] == false);
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
