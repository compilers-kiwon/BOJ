#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	NONE		0
#define	MAX_SIZE	(100000+1)

typedef	pair<int,int>	Supporter;

string	supporter_name[MAX_SIZE];

bool	input(int& n,int &m,map<string,int>& candidate_no,
			  vector<Supporter>& supporters)
{
	cin>>n>>m;
	
	if( n==0 && m==0 )
	{
		return	false;
	}
	
	for(int i=1;i<=n;i++)
	{
		string	candidate;
		
		cin>>candidate;
		candidate_no[candidate] = i;
	}
	
	int	back_ptr;
	
	back_ptr = n+1;
	
	for(int i=1;i<=m;i++)
	{
		string&	supporter = supporter_name[i];
		string	candidate;
		
		cin>>supporter>>candidate;
		
		int&	no = candidate_no[candidate];
		
		if( no == NONE )
		{
			no = back_ptr++;
		}
		
		supporters.push_back(make_pair(no,i));
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,m;
		
		map<string,int>		candidate_no;
		vector<Supporter>	supporters;
		
		if( input(n,m,candidate_no,supporters) == false )
		{
			break;
		}
		
		sort(supporters.begin(),supporters.end());
		
		for(int i=0;i<supporters.size();i++)
		{
			int&	s = supporters[i].second;
			
			cout<<supporter_name[s]<<'\n';
		}
	}
	
	return	0;
}
