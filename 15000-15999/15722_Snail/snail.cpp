#include	<iostream>

using namespace	std;

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	NEXT_DIR(d)	(((d)+1)%MAX_DIR)

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{1,0},{0,1},{-1,0},{0,-1}};

int	main(void)
{
	int	n,row,col,len,cnt,d;
	
	cin>>n;
	row = col = cnt = 0;
	len = 1;
	d = UP;
	
	for(int i=1;i<=n;i++)
	{
		row += adj[d].d_row;
		col += adj[d].d_col;
		cnt++;
		
		if( cnt == len )
		{
			cnt = 0;
			d = NEXT_DIR(d);
			
			if( d == DOWN || d == UP )
			{
				len++;
			}
		}
	}
	
	cout<<col<<' '<<row<<'\n';
	
	return	0;
}
