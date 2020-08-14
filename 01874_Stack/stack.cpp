#include	<cstdio>
#include	<stack>
#include	<vector>

using namespace	std;

#define	PUSH	'+'
#define	POP		'-'

stack<int>		st;
vector<char>	st_operation;

int	main(void)
{
	int		n,i,number_to_be_pushed;
	bool	result;
	
	scanf("%d",&n);
	
	for(i=1,number_to_be_pushed=1,result=true;i<=n;i++)
	{
		int	expected_number;
		
		scanf("%d",&expected_number);
		
		if( number_to_be_pushed == expected_number )
		{
			st_operation.push_back(PUSH);
			st_operation.push_back(POP);
			++number_to_be_pushed;
		}
		else if( number_to_be_pushed < expected_number )
		{
			for(;number_to_be_pushed<expected_number;++number_to_be_pushed)
			{
				st.push(number_to_be_pushed);
				st_operation.push_back(PUSH);
			}
			
			st_operation.push_back(PUSH);
			st_operation.push_back(POP);
			++number_to_be_pushed;
		}
		else	// number_to_be_pushed > expected_number
		{
			if( st.size() != 0 && st.top() == expected_number )
			{
				st.pop();
				st_operation.push_back(POP);
			}
			else
			{
				result = false;
				break;
			}
		}
	}
	
	if( result == true )
	{
		for(int j=0,len=st_operation.size();j<len;j++)
		{
			printf("%c\n",st_operation[j]);
		}
	}
	else
	{
		printf("No\n");
	}
	
	return	0;
}

