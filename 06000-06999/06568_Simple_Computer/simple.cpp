#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1<<5)
#define	MAX_VALUE	(1<<8)

#define	STA	0	// 000
#define	LDA	1	// 001
#define	BEQ	2	// 010
#define	NOP	3	// 011
#define	DEC	4	// 100
#define	INC	5	// 101
#define	JMP	6	// 110
#define	HLT	7	// 111

#define	char2int(c)	((int)((c)-'0'))

#define	get_opcode(m)	((m)>>5)
#define	get_operand(m)	((m)&0x1F)

const string	binary[0x10] = {"0000","0001","0010","0011","0100","0101","0110","0111",
								"1000","1001","1010","1011","1100","1101","1110","1111"};
								
int		str2int(const string& str)
{
	int	ret,i;
	
	for(i=ret=0;i<str.length();i++)
	{
		ret = ret*2+char2int(str[i]);
	}
	
	return	ret;
}

bool	input(vector<int>& program)
{
	for(int i=1;i<=MAX_SIZE;i++)
	{
		string		str;

		cin>>str;
		
		if( str == "" )
		{
			return	false;
		}
		
		program.push_back(str2int(str));
	}
	
	return	true;
}

int		simulate(vector<int>& program)
{
	int		acc,pc;
	bool	finished;
	
	for(acc=pc=0,finished=false;finished!=true;)
	{
		int	opcode,operand;

		opcode = get_opcode(program[pc]);
		operand = get_operand(program[pc]);
		pc = (pc+1)%MAX_SIZE;
		
		switch(opcode)
		{
			case	STA :
				program[operand] = acc;
				break;
			case	LDA :
				acc = program[operand];
				break;
			case	BEQ : 
				if( acc == 0 )
				{
					pc = operand;
				}
				break;
			case	DEC :
				acc = (acc+MAX_VALUE-1)%MAX_VALUE;
				break;
			case	INC :
				acc = (acc+1)%MAX_VALUE;
				break;
			case	JMP : 
				pc = operand;
				break;
			case	HLT:
				finished = true;
				break;
			case	NOP:
			default :
				// donothing
				break;
		}
	}
	
	return	acc;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		vector<int>	program;
		int			result;
		
		if( input(program) == false )
		{
			break;
		}
		
		result = simulate(program);
		cout<<binary[(result&0xF0)>>4]<<binary[result&0x0F]<<'\n';
	}
	
	return	0;
}
