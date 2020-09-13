#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_TRAIN	(100000+1)
#define	TRAIN_MASK			0x000FFFFF
#define	START_BIT			0x00100000


int		N,M,train[MAX_NUM_OF_TRAIN];
bool	visited[TRAIN_MASK+1];

inline void	take_on_passenger(int train_no,int seat_no)
{
	train[train_no] |= (START_BIT>>seat_no);
}

inline void	take_off_passenger(int train_no,int seat_no)
{
	train[train_no] &= ~(START_BIT>>seat_no);
}

inline void	move_backward(int train_no)
{
	train[train_no] = train[train_no]>>1; 
}

inline void	move_forward(int train_no)
{
	train[train_no] = (train[train_no]<<1)&TRAIN_MASK;
}

int		main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int m=1;m<=M;m++)
	{
		int	op,i,x;
		
		scanf("%d %d",&op,&i);
		
		switch(op)
		{
			case	1:
				scanf("%d",&x);
				take_on_passenger(i,x);
				break;
			case	2:
				scanf("%d",&x);
				take_off_passenger(i,x);
				break;
			case	3:
				move_backward(i);
				break;
			case	4:
				move_forward(i);
				break;
			default:
				// do nothing
				break;
		}
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( visited[train[i]] == false )
		{
			visited[train[i]] = true;
			cnt++;
		}
	}
	
	printf("%d\n",cnt);
	
	return	0;
}
