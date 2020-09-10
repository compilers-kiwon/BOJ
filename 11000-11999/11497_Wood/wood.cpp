#include	<iostream>
#include	<vector>
#include	<queue>
#include	<cmath>

using namespace	std;

void	place_wood(priority_queue<int>& wq,vector<int>& wood,int num_of_woods)
{
	int	head,tail;
	
	wood.resize(num_of_woods);
	
	for(head=0,tail=num_of_woods-1;head<tail;head++,tail--)
	{
		wood[head] = -wq.top();wq.pop();
		wood[tail] = -wq.top();wq.pop();
	}
	
	if( head == tail )
	{
		wood[head] = -wq.top();wq.pop();
	}
}

int		find_max_diff(vector<int>& wood,int num_of_woods)
{
	int	max_diff,i;
	
	for(i=1,max_diff=wood[num_of_woods-1]-wood[0];i<num_of_woods;i++)
	{
		max_diff = max(max_diff,abs(wood[i]-wood[i-1]));
	}
	return	max_diff;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		priority_queue<int>	wood_queue;
		vector<int>			wood;
		int					N;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			int	w;
			
			cin>>w;
			wood_queue.push(-w);
		}
		
		place_wood(wood_queue,wood,N);
		
		cout<<find_max_diff(wood,N)<<endl;
		
		T--;
	}
	return	0;
}
