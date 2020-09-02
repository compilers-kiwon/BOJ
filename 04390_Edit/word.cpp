#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE	25000
#define	MAX_LEN		16

typedef	pair<string,int>	Word;

int				dp[MAX_SIZE];
vector<int>		table[MAX_LEN+2];
vector<string>	dic;

void	input(void)
{
	for(int i=0;;i++)
	{
		string	str;
		
		cin>>str;
		
		if( str.empty() )
		{
			break;
		}
		
		dp[i] = -1;
		table[str.length()].push_back(i);
		dic.push_back(str);
	}
}

bool	compare_word(const string& s1,const string& s2,
					 const int& s1_ptr,const int& s2_ptr)
{
	for(int i=0;s1_ptr+i<s1.length();i++)
	{
		if( s1[s1_ptr+i] != s2[s2_ptr+i] )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	is_editable_by_deleting(const string& small,const string& big)
{
	int	ptr;
	
	for(ptr=0;ptr<small.length();ptr++)
	{
		if( small[ptr] != big[ptr] )
		{
			break;
		}
	}
	
	return	compare_word(small,big,ptr,ptr+1);
}

bool	is_editable_by_adding(const string& small,const string& big)
{
	return	is_editable_by_deleting(small,big);
}

bool	is_editable_by_changing(const string& s1,const string& s2)
{
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<s1.length()&&cnt<2;i++)
	{
		if( s1[i] != s2[i] )
		{
			cnt++;
		}
	}
	
	return	(cnt==1);
}

int		get_dp(int idx)
{
	int&			ret = dp[idx];
	const string&	current = dic[idx];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	vector<int>&	small = table[current.length()-1];
	vector<int>&	same = table[current.length()];
	vector<int>&	big = table[current.length()+1];
	
	for(int i=0;i<small.size();i++)
	{
		int&	adj_word_idx = small[i];
		
		if( adj_word_idx > idx )
		{
			break;
		}
		
		if( is_editable_by_deleting(dic[adj_word_idx],current) )
		{
			ret = max(ret,get_dp(adj_word_idx));
		}
	}
	
	for(int i=0;i<same.size();i++)
	{
		int&	adj_word_idx = same[i];
		
		if( adj_word_idx == idx )
		{
			break;
		}
		
		if( is_editable_by_changing(dic[adj_word_idx],current) )
		{
			ret = max(ret,get_dp(adj_word_idx));
		}
	}
	
	for(int i=0;i<big.size();i++)
	{
		int&	adj_word_idx = big[i];
		
		if( adj_word_idx > idx )
		{
			break;
		}
		
		if( is_editable_by_adding(current,dic[adj_word_idx]) )
		{
			ret = max(ret,get_dp(adj_word_idx));
		}
	}
	
	return	++ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int	max_len = 0;
	
	for(int i=0;i<dic.size();i++)
	{
		max_len = max(max_len,get_dp(i));
	}
	
	cout<<max_len<<'\n';
	
	return	0;
}
