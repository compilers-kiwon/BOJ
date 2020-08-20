#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE		(400+1)
#define	IN_RANGE(MIN,n)	((MIN)<=(n))

typedef	pair<int,int>	RowCol;

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		char			box[MAX_SIZE][MAX_SIZE+1];
		queue<RowCol>	h_queue,v_queue;
		int				r,c,cnt;
		
		scanf("%d %d",&r,&c);
		cnt = 0;
		
		for(int row=1;row<=r;row++)
		{
			scanf("%s",&box[row][1]);
			
			for(int col=1;col<=c;col++)
			{
				switch(box[row][col])
				{
					case	'^':
						v_queue.push(make_pair(row,col));
						break;
					case	'<':
						h_queue.push(make_pair(row,col));
						break;
					default:
						// do nothing
						break;
				}
			}
		}
		
		while( !h_queue.empty() )
		{
			int	current_row,current_col;
			
			current_row = h_queue.front().first;
			current_col = h_queue.front().second;
			
			h_queue.pop();
			
			if( IN_RANGE(1,current_col-2) && box[current_row][current_col-2]=='>' && box[current_row][current_col-1]=='o' )
			{
				cnt++;
			}
		}
		
		while( !v_queue.empty() )
		{
			int	current_row,current_col;
			
			current_row = v_queue.front().first;
			current_col = v_queue.front().second;
			
			v_queue.pop();
			
			if( IN_RANGE(1,current_row-2) && box[current_row-2][current_col]=='v' && box[current_row-1][current_col]=='o' )
			{
				cnt++;
			}
		}
		
		printf("%d\n",cnt);
		
		T--;
	}
	
	return	0;
}
