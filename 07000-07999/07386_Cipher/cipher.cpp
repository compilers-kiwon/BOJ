#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	0x100

void	analyze_str(const string& str,
					priority_queue<int>& q)
{
	int	cnt[MAX_SIZE];
	
	for(char c='A';c<='Z';c++)
	{
		cnt[c] = 0;
	}
	
	for(int i=0;i<str.length();i++)
	{
		cnt[str[i]]++;
	}
	
	for(char c='A';c<='Z';c++)
	{
		if( cnt[c] != 0 )
		{
			q.push(cnt[c]);
		}
	}
}

void	input(priority_queue<int>& p1,
			  priority_queue<int>& p2)
{
	string	s1,s2;
	
	cin>>s1>>s2;
	
	analyze_str(s1,p1);
	analyze_str(s2,p2);
}

bool	compare_analysis(priority_queue<int>& p1,
						 priority_queue<int>& p2)
{
	for(;!p1.empty()&&!p2.empty();p1.pop(),p2.pop())
	{
		if( p1.top() != p2.top() )
		{
			return	false;	
		}	
	}
	
	return	(p1.empty()&&p2.empty());	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<int>	p1,p2;
	
	input(p1,p2);
	
	if( compare_analysis(p1,p2) == false )
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
	
	return	0;
}
