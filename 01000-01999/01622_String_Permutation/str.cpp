#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100

int	cnt1[MAX_SIZE],cnt2[MAX_SIZE];

void	parse_str(const string& str,int* cnt)
{
	fill(&cnt['a'],&cnt['z'+1],0);
	
	for(int i=0;i<str.length();i++)
	{
		cnt[str[i]]++;
	}
}

void	find_max_sub_str(string& result)
{
	for(char c='a';c<='z';c++)
	{
		if( cnt1[c]==0 || cnt2[c]==0 )
		{
			continue;
		}
		
		for(int j=1;j<=min(cnt1[c],cnt2[c]);j++)
		{
			result.push_back(c);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	a,b;
		
		if( !(getline(cin,a),getline(cin,b)) )
		{
			break;
		}
		
		parse_str(a,cnt1);
		parse_str(b,cnt2);
		
		string	max_sub;
		
		find_max_sub_str(max_sub);
		cout<<max_sub<<'\n';
	}
	
	return	0;
}
