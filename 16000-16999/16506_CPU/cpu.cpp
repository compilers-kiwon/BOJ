#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<string,string>	opcode,operand;

void	init_table(void)
{
	opcode["ADD"] = "00000";
	opcode["SUB"] = "00010";
	opcode["MOV"] = "00100";
	opcode["AND"] = "00110";
	opcode["OR"] = "01000";
	opcode["NOT"] = "01010";
	opcode["MULT"] = "01100";
	opcode["LSFTL"] = "01110";
	opcode["LSFTR"] = "10000";
	opcode["ASFTR"] = "10010";
	opcode["RL"] = "10100";
	opcode["RR"] = "10110";
	
	opcode["ADDC"] = "00001";
	opcode["SUBC"] = "00011";
	opcode["MOVC"] = "00101";
	opcode["ANDC"] = "00111";
	opcode["ORC"] = "01001";
	opcode["MULTC"] = "01101";
	opcode["LSFTLC"] = "01111";
	opcode["LSFTRC"] = "10001";
	opcode["ASFTRC"] = "10011";
	opcode["RLC"] = "10101";
	opcode["RRC"] = "10111";
	
	operand["0"] = "000";
	operand["1"] = "001";
	operand["2"] = "010";
	operand["3"] = "011";
	operand["4"] = "100";
	operand["5"] = "101";
	operand["6"] = "110";
	operand["7"] = "111";
	operand["8"] = "1000";
	operand["9"] = "1001";
	operand["10"] = "1010";
	operand["11"] = "1011";
	operand["12"] = "1100";
	operand["13"] = "1101";
	operand["14"] = "1110";
	operand["15"] = "1111";
}

void	build_bin(string& bin,string& opc,string& rD,string& rA,string& rB_C)
{
	string&	current_opcode = opcode[opc];
	string&	flexible_operand = operand[rB_C];
	
	bin = current_opcode+"0"+operand[rD]+operand[rA];
	
	if( flexible_operand.length() == 3 )
	{
		if( current_opcode[current_opcode.length()-1] == '0' )
		{
			bin += flexible_operand+"0";
		}
		else
		{
			bin += "0"+flexible_operand;
		}
	}
	else
	{
		bin += flexible_operand;
	}
}

int		main(void)
{
	int		N;
	
	cin.sync_with_stdio(false);
	init_table();
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	instruction,opc,rD,rA,rB_C;
	
		cin>>opc>>rD>>rA>>rB_C;
		build_bin(instruction,opc,rD,rA,rB_C);
		cout<<instruction<<'\n';
	}
	
	return	0;
}
