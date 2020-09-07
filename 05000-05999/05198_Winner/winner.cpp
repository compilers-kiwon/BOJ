#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_CANDIDATES	100
#define	MAX_RACES		9
#define	char2int(c)		((int)((c)-'0'))

typedef	pair<int,string>	Candidate;

void	input(vector<Candidate>& c,vector<string>& vote,int& r)
{
	int	n,v;
	
	cin>>n>>r>>v;getchar();
	
	for(int i=1;i<=n;i++)
	{
		string		str;
		Candidate	d;
		
		getline(cin,str);
		
		d.first = char2int(str[0]);
		d.second = str.substr(2,str.length()-2);
		
		c.push_back(d);
	}
	
	for(int i=1;i<=v;i++)
	{
		string	str;
		
		cin>>str;
		vote.push_back(str);
	}
}

bool	is_valid(string& v,vector<Candidate>& c)
{
	bool	voted[MAX_RACES+1];
	
	fill(&voted[1],&voted[MAX_RACES+1],false);
	
	for(int i=0;i<v.length();i++)
	{
		if( v[i] == 'x' )
		{
			int&	r = c[i].first;
			
			if( voted[r] == true )
			{
				return	false;
			}
			
			voted[r] = true;
		}
	}
	
	return	true;
}

void	get_score(vector<Candidate>& c,vector<string>& vote,vector<int>& cnt)
{
	for(int i=0;i<vote.size();i++)
	{
		string& v = vote[i];
		
		if( is_valid(v,c) == false )
		{
			continue;
		}
		
		for(int i=0;i<v.length();i++)
		{
			if( v[i] == 'x' )
			{
				cnt[i]++;
			}
		}
	}
}

void	get_winner(vector<Candidate>& c,vector<int>& cnt,vector<int>* winner)
{
	vector<int>	win_cnt(MAX_RACES+1,0);
	
	for(int i=0;i<cnt.size();i++)
	{
		int&	r = c[i].first;
		
		if( cnt[i] >= win_cnt[r] )
		{
			if( cnt[i] > win_cnt[r] )
			{
				winner[r].clear();
				win_cnt[r] = cnt[i];
			}
			
			winner[r].push_back(i);
		}
	}
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		vector<Candidate>	candidate;
		vector<string>		vote;
		vector<int>			cnt,winner[MAX_RACES+1];
		int					r;
		bool				is_winner[MAX_CANDIDATES];
	
		input(candidate,vote,r);
		cnt.resize(candidate.size(),0);
		
		get_score(candidate,vote,cnt);
		get_winner(candidate,cnt,winner);
		
		cout<<"Data Set "<<k<<":\n";
		fill(&is_winner[0],&is_winner[candidate.size()],false);
		
		for(int i=1;i<=r;i++)
		{
			for(int j=0;j<winner[i].size();j++)
			{
				is_winner[winner[i][j]] = true;
			}
		}
		
		for(int i=0;i<candidate.size();i++)
		{
			if( is_winner[i] == true )
			{
				cout<<candidate[i].second<<'\n';
			}
		}
	}
	
	return	0;
}
