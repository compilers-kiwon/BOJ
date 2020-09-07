#include	<iostream>
#include	<queue>

using namespace	std;

#define	char2int(c)				((int)((c)-'0'))
#define	MAX_NUM					(1000000+1)
#define	MAX_NUM_OF_OPERATION	(10+1)

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	string	number;
	int		value,num_of_remaining_operation;
};

bool	visited[MAX_NUM][MAX_NUM_OF_OPERATION];

int		str2int(string& str)
{
	int	n,i;
	
	for(i=n=0;i<str.length();i++)
	{
		n = n*10+char2int(str[i]);
	}
	
	return	n;
}

int		find_max_num(string& init,int num_of_allowed_operation)
{
	State			s;
	queue<State>	state_q;
	int				max_num;
	
	s.number = init;
	s.num_of_remaining_operation = num_of_allowed_operation;
	s.value = str2int(init);
	
	state_q.push(s);
	visited[s.value][num_of_allowed_operation] = true;
	max_num = -1;
	
	while( state_q.size() != 0 )
	{
		State	current;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.num_of_remaining_operation == 0 )
		{
			max_num = max(max_num,current.value);
			continue;
		}
		
		for(int i=0;i<current.number.length()-1;i++)
		{
			for(int j=i+1;j<current.number.length();j++)
			{
				if( (i==0 && current.number[j] == '0') )
				{
					continue;
				}
				
				State	next;
				
				next.number = current.number;
				swap(next.number[i],next.number[j]);
				
				next.value = str2int(next.number);
				next.num_of_remaining_operation = current.num_of_remaining_operation-1;
				
				if( visited[next.value][next.num_of_remaining_operation] == false )
				{
					visited[next.value][next.num_of_remaining_operation] = true;
					state_q.push(next);
				}
			}
		}
	}
	
	return	max_num;
}

int		main(void)
{
	string	N;
	int		K;
	
	cin>>N>>K;
	cout<<find_max_num(N,K)<<endl;	
	
	return	0;	
}
