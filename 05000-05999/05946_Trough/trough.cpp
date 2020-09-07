#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	IMPOSSIBLE	0
#define	NOT_UNIQUE	2

typedef	pair<string,int>	Query;

int				N,M;
Query			q[MAX_SIZE];
vector<char>	solution;

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		cin>>q[i].first>>q[i].second;
	}
}

bool	check(vector<char>& str)
{
	bool	ret;
	
	ret = true;
	
	for(int i=1;i<=M&&ret==true;i++)
	{
		int		cnt;
		string&	s = q[i].first;
		int&	expected = q[i].second;
		
		cnt = 0;
		
		for(int j=0;j<N;j++)
		{
			if( s[j]=='1' && str[j]=='1' )
			{
				cnt++;
			}
		}
		
		if( cnt != expected )
		{
			ret = false;
		}
	}
	
	return	ret;
}

void	build_str(int len,vector<char>& str,int& cnt)
{
	if( len == N )
	{
		if ( check(str) == true )
		{
			solution = str;
			cnt++;
		}
		
		return;
	}
	
	str.push_back('0');
	build_str(len+1,str,cnt);
	
	if( cnt == NOT_UNIQUE )
	{
		return;
	}
	else
	{
		str.pop_back();
	}
	
	str.push_back('1');
	build_str(len+1,str,cnt);
	
	if( cnt == NOT_UNIQUE )
	{
		return;
	}
	else
	{
		str.pop_back();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				cnt;
	vector<char>	str;
	
	cnt = 0;
	input();
	
	build_str(0,str,cnt);
	
	switch(cnt)
	{
		case	0:
			cout<<"IMPOSSIBLE\n";
			break;
		case	1:
			for(int i=0;i<N;i++)
			{
				cout<<solution[i];
			}
			cout<<'\n';
			break;
		default:
			cout<<"NOT UNIQUE\n";
			break;
	}
	
	return	0;
}
