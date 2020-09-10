#include	<iostream>

using namespace std;

#define	MAX_NUM_OF_VERTEX	(100+1)

#define	TRUE	1
#define	FALSE	0

int	graph[MAX_NUM_OF_VERTEX][MAX_NUM_OF_VERTEX];
int	stack[MAX_NUM_OF_VERTEX],sp;
int	N;

#define	PUSH_STACK(v)	(stack[sp++]=(v))
#define	POP_STACK(v)	(stack[--sp])
#define	SIZE_OF_STACK()	(sp)

int	main(void)
{	
	cin>>N;
	
	for(int	i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			int	n;
			
			cin>>n;
			graph[i][j] = n;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		sp = 0;
		for(int j=1;j<=N;j++)
		{
			if( graph[i][j] == TRUE )
			{
				PUSH_STACK(j);
			}
		}
		
		while( SIZE_OF_STACK() != 0 )
		{
			int	current_v;
			
			current_v = POP_STACK();
			
			for(int j=1;j<=N;j++)
			{
				if( graph[i][j] == FALSE && graph[current_v][j] == TRUE )
				{
					PUSH_STACK(j);
					graph[i][j] = TRUE;
				}
			}	
		}				
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cout<<graph[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return	0;
}
