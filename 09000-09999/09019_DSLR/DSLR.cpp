#include	<iostream>
#include	<queue>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_DIGIT	4
#define	MAX_NUM		9999

int		prev_num[MAX_NUM+1];
char	operation[MAX_NUM+1];

void	find_min_num_of_operation(int A,int B)
{
	queue<int>		number_q;
	vector<bool>	visited(MAX_NUM+1,false);
	
	number_q.push(A);
	visited[A] = true;
	prev_num[A] = -1;
	
	while( !number_q.empty() )
	{
		int	current_value,next_value;
		
		current_value = number_q.front();
		number_q.pop();
		
		if( current_value == B )
		{
			break;
		}
		
		// "D"
		next_value = (2*current_value)%10000;
		
		if( visited[next_value] == false )
		{
			visited[next_value] = true;
			operation[next_value] = 'D';
			prev_num[next_value] = current_value;
			
			number_q.push(next_value);
		}
		
		// "S"
		next_value = (current_value==0)?MAX_NUM:(current_value-1);
		
		if( visited[next_value] == false )
		{
			visited[next_value] = true;
			operation[next_value] = 'S';
			prev_num[next_value] = current_value;
			
			number_q.push(next_value);
		}
		
		// "L"
		next_value = ((current_value*10)%10000)+(current_value/1000);
		
		if( visited[next_value] == false )
		{
			visited[next_value] = true;
			operation[next_value] = 'L';
			prev_num[next_value] = current_value;
			
			number_q.push(next_value);
		}
		
		// "R"
		next_value = (current_value/10)+(current_value%10)*1000;
		
		if( visited[next_value] == false )
		{
			visited[next_value] = true;
			operation[next_value] = 'R';
			prev_num[next_value] = current_value;
			
			number_q.push(next_value);
		}
	}
}

int		main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		int		A,B;
		
		cin>>A>>B;
		find_min_num_of_operation(A,B);
		
		vector<char>	op_history;
		
		for(int i=B;prev_num[i]!=-1;i=prev_num[i])
		{
			op_history.push_back(operation[i]);
		}
		
		for(int i=op_history.size()-1;i>=0;i--)
		{
			cout<<op_history[i];
		}
		cout<<'\n';
		
		T--;
	}
	
	return	0;
}
