#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE_OF_DIC	(5000+1)
#define	MAX_WORD_LEN	15

#define	get_index(c)	((int)((c)-'a'))

#define	TRUE	1
#define	FALSE	0

int		dic[MAX_SIZE_OF_DIC][MAX_WORD_LEN];

void	read_dic(int index)
{
	string	str;
	
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		dic[index][i] = 1<<get_index(c);
	}
}

int		count(vector<int>& p,int num_of_words)
{	
	int	cnt;

	cnt = 0;
	
	for(int i=1;i<=num_of_words;i++)
	{
		int	result;
		
		result = TRUE;
		
		for(int j=0;j<p.size();j++)
		{
			if( (dic[i][j]&p[j]) == 0 )
			{
				result = FALSE;
				break;
			}
		}
		
		cnt += result;
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				L,D,N;
	
	cin>>L>>D>>N;
	
	for(int i=1;i<=D;i++)
	{
		read_dic(i);
	}
	
	for(int i=1;i<=N;i++)
	{
		vector<int>	pattern(L,0);
		string		p;
		bool		is_group;
		int			index,cnt;
		
		cin>>p;
		
		is_group = false;
		index = 0;
		
		for(int j=0;j<p.length();j++)
		{
			char&	c = p[j];
			int		t;
			
			if( c == '(' )
			{
				is_group = true;
				t = 0;
				
				continue;
			}
			
			if( c == ')' )
			{
				is_group = false;
				pattern[index++] = t;
				
				continue;
			}
			
			if( is_group == true )
			{
				t |= 1<<get_index(c);
			}
			else
			{
				pattern[index++] = 1<<get_index(c);
			}
		}
		
		cnt = count(pattern,D);
		cout<<"Case #"<<i<<": "<<cnt<<'\n';
	}
	
	return	0;
}
