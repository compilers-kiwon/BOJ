#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN		(50000+1)
#define	CNT_SIZE	26

#define	index(c)	((int)((c)-'a'))

#define	POSSIBLE	"DA"
#define	IMPOSSIBLE	"NE"

#define	get_num_of_char(c,s,e)	(cnt_table[index((c))][(e)]-cnt_table[index(c)][(s)-1])

int	cnt_table[CNT_SIZE][MAX_LEN];

void	init(string& str)
{
	str.insert(str.begin(),' ');
	
	for(int col=1;col<str.length();col++)
	{
		for(int row=index('a');row<=index('z');row++)
		{
			cnt_table[row][col] = cnt_table[row][col-1];
		}
		
		cnt_table[index(str[col])][col]++;
	}
}

bool	check_query(int A,int B,int C,int D)
{
	bool	ret;
	char	c;
	
	for(ret=true,c='a';c<='z';c++)
	{
		if( get_num_of_char(c,A,B) != get_num_of_char(c,C,D) )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	S;
	int		Q;
	
	cin>>S;
	init(S);
	
	cin>>Q;
	
	for(int i=1;i<=Q;i++)
	{
		int	A,B,C,D;
		
		cin>>A>>B>>C>>D;
		
		if( check_query(A,B,C,D) == true )
		{
			cout<<POSSIBLE<<'\n';
		}
		else
		{
			cout<<IMPOSSIBLE<<'\n';
		}
	}
	
	return	0;
}
