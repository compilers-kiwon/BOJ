#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	GET_INDEX(c)	((int)((c)-'a'))
#define	NUM_OF_CHARS	26
#define	MAX_LEN			(5000+1)

void	count_char(char* str,vector<int>& count_table,int& max_num)
{
	for(int i=0;str[i]!='\n';i++)
	{
		if( str[i] == ' ' )
		{
			continue;
		}
		
		max_num = max(max_num,++count_table[GET_INDEX(str[i])]);
	}
}

int		main(void)
{
	vector<int>	cnt(NUM_OF_CHARS,0);
	int			max_num;
	char		buf[MAX_LEN+1];
	
	max_num = 0;
	
	while( fgets(buf,MAX_LEN,stdin) != NULL )
	{
		count_char(buf,cnt,max_num);
	}
		
	for(char c='a';c<='z';c++)
	{
		if( cnt[GET_INDEX(c)] == max_num )
		{
			cout<<c;
		}
	}
	cout<<'\n';
	
	return	0;
}
