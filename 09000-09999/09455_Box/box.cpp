#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_COL	(100+1)

#define	EMPTY		0
#define	NOT_EMPTY	1

priority_queue<int>	box_pq[MAX_COL];

void	input(int& row_size,int& col_size)
{
	cin>>row_size>>col_size;
	
	for(int i=row_size;i>=1;i--)
	{
		for(int j=1;j<=col_size;j++)
		{
			int	state;
			
			cin>>state;
			
			if( state == NOT_EMPTY )
			{
				box_pq[j].push(-i);
			}
		}
	}
}

int		count_box_movements_at_col(int col)
{
	int	cnt,prev_diff,current_diff;
	int	prev_box_row,current_box_row;
	
	prev_box_row = 0;
	cnt = 0;
	prev_diff = 0;
	
	while( box_pq[col].size() != 0 )
	{
		current_box_row = -(box_pq[col].top());
		box_pq[col].pop();
		
		current_diff = prev_diff+(current_box_row-prev_box_row-1);
		cnt += current_diff;
		prev_box_row = current_box_row;
		prev_diff = current_diff;
	}
	
	return	cnt;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	row,col;
		int	cnt,i;
		
		input(row,col);
		
		for(cnt=0,i=1;i<=col;i++)
		{
			if( box_pq[i].size() != 0 )
			{
				cnt += count_box_movements_at_col(i);
			}
		}
		cout<<cnt<<endl;
		
		T--;
	}
	return	0;
}
