#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_LEN			100
#define	MAX_DIC_SIZE	0x100
#define	MAX_DIAL		10
#define	INF				50000

typedef	pair<string,string>	WordNum;	// first:word_str, second:num_str

string			phone_number;
int				n,K;
bool			visited[MAX_LEN];
vector<string>	dp[MAX_LEN];
vector<WordNum>	dictionary[MAX_DIC_SIZE];
char			dial[MAX_DIC_SIZE];

const string	input[MAX_DIAL] = {"oqz","ij","abc","def","gh","kl","mn","prs","tuv","wxy"};
const string	int2char = "0123456789";

void	init(void)
{
	for(int i=0;i<MAX_DIAL;i++)
	{
		for(int j=0;j<input[i].length();j++)
		{
			dial[input[i][j]] = int2char[i];
		}
	}
}

void	str2num(string& str,string& num)
{
	for(int i=0;i<str.length();i++)
	{
		num.push_back(dial[str[i]]);
	}
}

void	input_data(void)
{
	cin>>phone_number>>n;
	
	for(int i=1;i<=n;i++)
	{
		WordNum	wn;
		
		cin>>wn.first;
		str2num(wn.first,wn.second);
		
		char&	last_num = wn.second[wn.second.length()-1];
		
		dictionary[last_num].push_back(wn);
	}
}

bool	compare_number(int ptr,string& n)
{
	for(int tail=n.length()-1;tail>=0;tail--,ptr--)
	{
		if( phone_number[ptr] != n[tail] )
		{
			return	false;
		}
	}
	
	return	true;
}
int		get_dp(int num_idx)
{
	int	min_num_of_words,min_idx;
	
	if( num_idx == -1 )
	{
		return	0;
	}
	
	if( visited[num_idx] == true )
	{
		int	ret;
		
		ret = dp[num_idx].size();
		
		if( ret == 0 )
		{
			ret = INF;
		}
		
		return	ret;
	}
	
	visited[num_idx] = true;
	
	string				w;	
	vector<WordNum>&	candidate = dictionary[phone_number[num_idx]];
		
	min_num_of_words = INF;
	
	for(int i=0;i<candidate.size();i++)
	{
		string&	c = candidate[i].second;
		
		if( c.length()<=num_idx+1 && compare_number(num_idx,c)!=false )
		{
			int	d;
			
			d = get_dp(num_idx-c.length());
			
			if( d < min_num_of_words )
			{
				min_num_of_words = d;
				min_idx = num_idx-c.length();
				w = candidate[i].first;
			}
		}
	}
	
	if( min_num_of_words != INF )
	{
		dp[num_idx] = dp[min_idx];
		dp[num_idx].push_back(w);
		min_num_of_words++;
	}
	
	return	min_num_of_words;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	input_data();
	
	K = get_dp(phone_number.length()-1);
	
	if( K == INF )
	{
		cout<<"0\nNo solution.\n";
	}
	else
	{
		cout<<K<<'\n';
		
		vector<string>&	s = dp[phone_number.length()-1];
		
		for(int i=0;i<s.size();i++)
		{
			cout<<s[i]<<'\n';
		}
	}
	
	return	0;
}
