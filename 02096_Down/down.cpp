#include	<cstdio>
#include	<iostream>

using namespace	std;

#define	LEFT	0
#define	MIDDLE	1
#define	RIGHT	2
#define	MAX_LEN	3

pair<int,int>	current_state[MAX_LEN],prev_state[MAX_LEN];	//first:min,second:max;

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	prev_state[LEFT].first = prev_state[LEFT].second =
	prev_state[MIDDLE].first = prev_state[MIDDLE].second =
	prev_state[RIGHT].first = prev_state[RIGHT].second = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	left,middle,right;
		
		scanf("%d %d %d",&left,&middle,&right);
		
		current_state[LEFT].first = left+min(prev_state[LEFT].first,prev_state[MIDDLE].first);
		current_state[LEFT].second = left+max(prev_state[LEFT].second,prev_state[MIDDLE].second);
		
		current_state[MIDDLE].first = middle+min(prev_state[RIGHT].first,min(prev_state[LEFT].first,prev_state[MIDDLE].first));
		current_state[MIDDLE].second = middle+max(prev_state[RIGHT].second,max(prev_state[LEFT].second,prev_state[MIDDLE].second));
		
		current_state[RIGHT].first = right+min(prev_state[RIGHT].first,prev_state[MIDDLE].first);
		current_state[RIGHT].second = right+max(prev_state[RIGHT].second,prev_state[MIDDLE].second);
		
		prev_state[LEFT] = current_state[LEFT];
		prev_state[MIDDLE] = current_state[MIDDLE];
		prev_state[RIGHT] = current_state[RIGHT];
	}
	
	printf("%d %d\n",max(max(current_state[LEFT].second,current_state[MIDDLE].second),current_state[RIGHT].second),
		min(min(current_state[LEFT].first,current_state[MIDDLE].first),current_state[RIGHT].first));
		
	return	0;
}
