#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	0x100
#define	MAX_LEN		100

#define	TRUE	1
#define	FALSE	0
#define	TBD		-1

string			S;
int				N,dp[MAX_LEN];
vector<string>	A[MAX_SIZE];

int		get_dp(int ptr)
{
	if( ptr == -1 )
	{
		return	TRUE;
	}
	
	int&	ret = dp[ptr];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = FALSE;
	
	vector<string>&	candidates = A[S[ptr]];
	
	for(int i=0;i<candidates.size()&&ret==FALSE;i++)
	{
		string&	c = candidates[i];
		
		if( c.length() > ptr+1 )
		{
			continue;
		} 
		
		bool	flag;
		
		flag = true;
		
		for(int j=0;j<c.length();j++)
		{
			char&	s = S[ptr-j];
			char&	a = c[c.length()-1-j];
			
			if( s != a )
			{
				flag = false;
				break;
			}
		}
		
		if( flag == false )
		{
			continue;
		}
		
		ret = get_dp(ptr-c.length());
	}
	
	return	ret;
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>S>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	a;
		
		cin>>a;
		A[a[a.length()-1]].push_back(a);
	}
	
	fill(&dp[0],&dp[S.length()],TBD);
}

int		main(void)
{
	init();
	
	cout<<get_dp(S.length()-1)<<'\n';
	
	return	0;
}
