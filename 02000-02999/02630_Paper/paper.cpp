#include	<iostream>

using namespace	std;

typedef	pair<int,int>	Paper;

#define	WHITE		0
#define	BLUE		1

#define	MAX_SIZE	128

int	paper[MAX_SIZE][MAX_SIZE];

Paper	cut_paper(int row,int col,int size)
{
	Paper	result,p1,p2,p3,p4;
	int		cut_size,white_cnt,blue_cnt;
	
	if( size == 1 )
	{
		if( paper[row][col] == WHITE )
		{
			result.first = 1;
			result.second = 0;
		}
		else
		{
			result.first = 0;
			result.second = 1;
		}
		return	result;
	}
	
	cut_size = size/2;
	
	p1 = cut_paper(row,col,cut_size);
	p2 = cut_paper(row,col+cut_size,cut_size);
	p3 = cut_paper(row+cut_size,col+cut_size,cut_size);
	p4 = cut_paper(row+cut_size,col,cut_size);
	
	white_cnt = p1.first+p2.first+p3.first+p4.first;
	blue_cnt = p1.second+p2.second+p3.second+p4.second;
	
	if( white_cnt == 0 )
	{
		blue_cnt = 1;
	}
	else if( blue_cnt == 0 )
	{
		white_cnt = 1;
	}
	result = make_pair(white_cnt,blue_cnt);
	
	return	result;
}

int		main(void)
{
	int		N;
	Paper	p;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>paper[i][j];
		}
	}
	
	 p = cut_paper(0,0,N);
	 
	 cout<<p.first<<endl<<p.second<<endl;
	 
	 return	0;
}
