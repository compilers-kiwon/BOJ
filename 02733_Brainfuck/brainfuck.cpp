#include	<iostream>
#include	<string>
#include	<vector>
#include	<stack>

using namespace	std;

#define	MAX_SIZE	1000000
#define	MEM_SIZE	32768
#define	MAX_VALUE	256

#define	inc(n,m)	((n)+1==m?0:(n)+1)
#define	dec(n,m)	((n)==0?(m)-1:(n)-1)

int		jump_table[MAX_SIZE];

void	input(vector<string>& program)
{
	for(;;)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "end" )
		{
			break;
		}
		
		program.push_back(str);
	}
}

bool	preprocessing(string& p,vector<string>& program)
{
	// 1. remove comments
	for(int i=0;i<program.size();i++)
	{
		for(int j=0;j<program[i].length();j++)
		{
			char&	c = program[i][j];
			
			if( c == '%' )
			{
				break;
			}
			
			p.push_back(c);
		}
	}
	
	// 2. build jump table
	stack<int>	st;
	
	for(int i=0;i<p.length();i++)
	{
		char&	c = p[i];
		
		switch(c)
		{
			case	'[':
				st.push(i);
				break;
			case	']':
				if( st.empty() )
				{
					return	false;
				}
				
				jump_table[st.top()] = i;
				jump_table[i] = st.top();
				
				st.pop();
				break;
			default:
				// do nothing
				break;
		}
	}
	
	if( !st.empty() )
	{
		return	false;
	}
	
	return	true;
}

void	run_program(string& program,string& result)
{
	int		ptr;
	char	mem[MEM_SIZE];
	
	ptr = 0;
	fill(&mem[0],&mem[MEM_SIZE],0);
	
	for(int i=0;i<program.length();i++)
	{
		char&	c = program[i];

		switch(c)
		{
			case	'>':
				ptr = inc(ptr,MEM_SIZE);
				break;
			case	'<':
				ptr = dec(ptr,MEM_SIZE);
				break;
			case	'+':
				mem[ptr] = inc(mem[ptr],MAX_VALUE);
				break;
			case	'-':
				mem[ptr] = dec(mem[ptr],MAX_VALUE);
				break;
			case	'.':
				result.push_back(mem[ptr]);
				break;
			case	'[':
				if( mem[ptr] == 0 )
				{
					i = jump_table[i]-1;
				}
				break;
			case	']':
				if( mem[ptr] != 0 )
				{
					i = jump_table[i]-1;
				}
				break;
			default:
				// do nothing
				break;
		}
	}
}

int		main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		vector<string>	program;
		string			preprocessed,result;
		
		input(program);
		cout<<"PROGRAM #"<<i<<":\n";
		
		if( preprocessing(preprocessed,program) == false )
		{
			cout<<"COMPILE ERROR\n";
			continue;
		}
		
		run_program(preprocessed,result);
		cout<<result<<'\n';
	}
	
	return	0;
}
