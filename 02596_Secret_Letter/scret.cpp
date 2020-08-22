#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	CODE_LEN	6

map<char,string>	alphabet_table;

void	init_alphabet_table(void)
{
	alphabet_table['A'] = "000000";
	alphabet_table['B'] = "001111";
	alphabet_table['C'] = "010011";
	alphabet_table['D'] = "011100";
	alphabet_table['E'] = "100110";
	alphabet_table['F'] = "101001";
	alphabet_table['G'] = "110101";
	alphabet_table['H'] = "111010";
}

int		count_diff(char c,string& code)
{
	string&	str = alphabet_table[c];
	int		cnt,i;
	
	for(cnt=i=0;i<CODE_LEN;i++)
	{
		if( str[i] != code[i] )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int		N,i,code_start_index;
	string	str,decode;
	
	init_alphabet_table();
	
	cin>>N>>str;
	
	for(i=1,code_start_index=0;i<=N;i++,code_start_index+=CODE_LEN)
	{
		string	code;
		int		min_diff,num_of_min_diff_alphabet;
		char	min_diff_char;
		
		code = str.substr(code_start_index,CODE_LEN);
		min_diff = CODE_LEN+1;
		
		for(char c='A';c<='H';c++)
		{
			int	diff;
			
			diff = count_diff(c,code);
			
			if( diff < min_diff )
			{
				min_diff = diff;
				num_of_min_diff_alphabet = 1;
				min_diff_char = c;
			}
			else if( diff == min_diff )
			{
				num_of_min_diff_alphabet++;
			}
		}
		
		if( num_of_min_diff_alphabet == 1 )
		{
			decode.push_back(min_diff_char);
		}
		else
		{
			break;
		}
	}
	if( i <= N )
	{
		cout<<i<<endl;
	}
	else
	{
		cout<<decode<<endl;
	}
	
	return	0;
}
