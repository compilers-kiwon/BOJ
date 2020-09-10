#include	<iostream>
#include	<map>

using namespace	std;

typedef	long long int	int64;

#define	ADD		0
#define	SUB		1
#define	MUL		2
#define	MAX_OP	3

#define	MAX_NUM_OF_EXP	(2500+1)

pair<int,int>		exp[MAX_NUM_OF_EXP];
int					visited[MAX_NUM_OF_EXP];
int64				exp_result[MAX_NUM_OF_EXP][MAX_OP];
map<int64,int>		assigned_exp;
pair<char,int64>	answer_table[MAX_NUM_OF_EXP];

const char			operators[MAX_OP] = {'+','-','*'};

int64	calculate(int n1,int n2,int op)
{
	int64	ret;
	
	switch(op)
	{
		case	ADD:
			ret = n1+n2;
			break;
		case	SUB:
			ret = n1-n2;
			break;
		case	MUL:
			ret = (int64)n1*(int64)n2;
			break;
		default:
			// do nothing
			break;
	}
	
	return	ret;
}

bool	dfs(int current_exp_index,int level)
{
	if( visited[current_exp_index] == level )
	{
		return	false;
	}
	
	visited[current_exp_index] = level;
	
	for(int i=0;i<MAX_OP;i++)
	{
		int	prev_assigned_exp;
		
		prev_assigned_exp = assigned_exp[exp_result[current_exp_index][i]];
		
		if( prev_assigned_exp == 0 || dfs(prev_assigned_exp,level) == true )
		{
			assigned_exp[exp_result[current_exp_index][i]] = current_exp_index;
			
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	int		n;
	bool	result;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&exp[i].first,&exp[i].second);
		
		for(int op=ADD;op<=MUL;op++)
		{
			exp_result[i][op] = calculate(exp[i].first,exp[i].second,op);
		}
	}

	result = true;
	
	for(int i=1;i<=n;i++)
	{
		if( dfs(i,i) == false )
		{
			result = false;
			break;
		}
	}
	
	if( result == false )
	{
		puts("impossible");
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int op=ADD;op<=MUL;op++)
			{
				if( assigned_exp[exp_result[i][op]] == i )
				{
					answer_table[i].first = operators[op];
					answer_table[i].second = exp_result[i][op];
				}
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			printf("%d %c %d = %lld\n",exp[i].first,answer_table[i].first,exp[i].second,answer_table[i].second);
		}
	}
	
	return	0;
}
