#include	<iostream>
#include	<string>

using namespace	std;

#define	CODE_TABLE_SIZE	(52+1)
#define	CNT_TABLE_SIZE	0x100

void	build_code_table(char* code_table)
{
	int		i;
	char	c;
	
	for(i=1,c='A';i<=26;i++,c++)
	{
		code_table[i] = c;
	}
	
	for(i=27,c='a';i<=52;i++,c++)
	{
		code_table[i] = c;
	}
	
	code_table[0] = ' ';
}

void	get_cnt_table(int* cnt_table,string& str)
{
	for(int i=0;i<str.length();i++)
	{
		cnt_table[str[i]]++;
	}
}

char	compare_cnt_table(int* t1,int* t2)
{
	for(int i=0;i<CNT_TABLE_SIZE;i++)
	{
		if( t1[i] != t2[i] )
		{
			return	'n';
		}
	}
	
	return	'y';
}

int		main(void)
{
	int		N,cnt1[CNT_TABLE_SIZE],cnt2[CNT_TABLE_SIZE];
	char	code_table[CODE_TABLE_SIZE];
	string	encode,src;
	
	build_code_table(code_table);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	a;
		
		cin>>a;
		encode.push_back(code_table[a]);
	}
	
	getchar();
	getline(cin,src);
	
	for(int i=0;i<CNT_TABLE_SIZE;i++)
	{
		cnt1[i] = cnt2[i] = 0;
	}
	
	get_cnt_table(cnt1,encode);
	get_cnt_table(cnt2,src);
	
	cout<<compare_cnt_table(cnt1,cnt2)<<'\n';
	
	return	0;
}
