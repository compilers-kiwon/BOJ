#include <iostream>

using namespace std;

#define MAX_SIZE 6561
#define UNIT_SIZE 3
#define MIDDLE_CNT 4

char grid[MAX_SIZE][MAX_SIZE+1];

void print(int row,int col,int size)
{
	if( size == UNIT_SIZE )
	{
		for(int i=0;i<UNIT_SIZE;i++)
		{
			fill(&grid[row+i][col],&grid[row+i][col+UNIT_SIZE],'*');
		}
		grid[row+UNIT_SIZE/2][col+UNIT_SIZE/2] = ' ';
		
		return;
	}
	
	int next_size,cnt;
	
	cnt = 0;
	next_size = size/3;
	
	for(int d_row=0;d_row<UNIT_SIZE;d_row++)
	{
		for(int d_col=0;d_col<UNIT_SIZE;d_col++)
		{
			if( cnt != MIDDLE_CNT )
			{
				print(row+d_row*next_size,col+d_col*next_size,next_size);
			}
			cnt++;
		}
	}
	
	int mid_row,mid_col;
	
	mid_row = row+(UNIT_SIZE/2)*next_size;
	mid_col = col+(UNIT_SIZE/2)*next_size;
	
	for(int i=0;i<next_size;i++)
	{
		fill(&grid[mid_row+i][mid_col],&grid[mid_row+i][mid_col+next_size],' ');
	}
}

int main(void)
{
	int N;
	
	cin>>N;
	print(0,0,N);
    
	for(int row=0;row<N;row++)
	{
		cout<<&grid[row][0]<<'\n';
	}
	
	return 0;
}
