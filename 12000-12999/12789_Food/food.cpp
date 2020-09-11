#include	<iostream>
#include	<stack>

using namespace	std;

#define	MAX_NUM_OF_STUDENTS	(1000+1)

int	main(void)
{
	int			N,i;
	bool		in_stack[MAX_NUM_OF_STUDENTS];
	stack<int>	st;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		in_stack[i] = false;
	}
	
	for(i=1;i<=N;)
	{
		int	M;
		
		if( in_stack[i] == true )
		{
			if( st.top() != i )
			{
				break;
			}
			st.pop();
			i++;
			continue;
		}
		
		cin>>M;
		
		if( M != i )
		{
			st.push(M);
			in_stack[M] = true;
		}
		else
		{
			i++;
		}
	}
	
	if( st.empty() == true )
	{
		cout<<"Nice\n";
	}
	else
	{
		cout<<"Sad\n";
	}
	
	return	0;
}
