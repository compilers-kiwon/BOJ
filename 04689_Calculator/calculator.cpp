#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_DIGIT	16
#define	MAX_SIZE	7

const char int2char[MAX_DIGIT] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int	char2int[0x100];

bool	convert(char* n,int from_base,int to_base,string& out)
{
	int	value,i;
	
	for(value=i=0;n[i]!='\0';i++)
	{
		value = value*from_base+char2int[n[i]];	
	}
	
	for(;value>0;value/=to_base)
	{
		out.push_back(int2char[value%to_base]);
	}
	
	if( out.length() > MAX_SIZE )
	{
		return	false;
	}
	
	for(;out.length()<MAX_SIZE;out.push_back(' '));
	
	for(int h=0,t=MAX_SIZE-1;h<t;h++,t--)
	{
		swap(out[h],out[t]);
	}
	
	return	true;	
}

int		main(void)
{
	char	number[MAX_SIZE+1];
	int		from_base,to_base;
	
	char2int['0'] = 0;
	char2int['1'] = 1;
	char2int['2'] = 2;
	char2int['3'] = 3;
	char2int['4'] = 4;
	char2int['5'] = 5;
	char2int['6'] = 6;
	char2int['7'] = 7;
	char2int['8'] = 8;
	char2int['9'] = 9;
	char2int['A'] = 10;
	char2int['B'] = 11;
	char2int['C'] = 12;
	char2int['D'] = 13;
	char2int['E'] = 14;
	char2int['F'] = 15;
	
	for(;scanf("%s %d %d",number,&from_base,&to_base)==3;)
	{
		string	str;
		
		if( convert(number,from_base,to_base,str) == false )
		{
			cout<<"  ERROR\n";
		}
		else
		{
			cout<<str<<'\n';
		}
	}
	
	return	0;
}
