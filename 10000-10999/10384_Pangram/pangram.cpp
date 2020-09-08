#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_PANGRAM_LEVEL	3
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	DIFF	0x20
				
const string	answer[MAX_PANGRAM_LEVEL+1] = {"Not a pangram","Pangram!","Double pangram!!","Triple pangram!!!"};

void	count_alphabet(string& str,vector<int>& cnt)
{
	for(int i=0;i<str.length();i++)
	{
		if( IN_RANGE('A',str[i],'Z') == true )
		{
			cnt[str[i]+DIFF]++;
		}
		else
		{
			cnt[str[i]]++;
		}
	}
}

int		solve(vector<int>& cnt)
{
	int		min_num;
	char	c;
	
	for(min_num=MAX_PANGRAM_LEVEL,c='a';c<='z';c++)
	{
		min_num = min(min_num,cnt[c]);
	}
	
	return	min_num;
}

int		main(void)
{
	int	n;
	
	cin>>n;getchar();
	
	for(int i=1;i<=n;i++)
	{
		string		str;
		vector<int>	cnt(0x100,0);
		
		getline(cin,str);
		count_alphabet(str,cnt);
		
		cout<<"Case "<<i<<": "<<answer[solve(cnt)]<<'\n';
	}
	
	return	0;
}
