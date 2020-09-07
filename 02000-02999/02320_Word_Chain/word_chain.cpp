#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_NUM_OF_WORDS	16
#define	BACK_CHAR(str)		((str)[(str).length()-1])
#define	init_dp(c,s)		(dp[(c)].resize(1<<((s)+1),-1))

typedef	vector<int>	DP;
typedef	vector<int>	Index;

map<char,DP>	dp;
string			word[MAX_NUM_OF_WORDS];
map<char,Index>	head;
vector<int>		connected[MAX_NUM_OF_WORDS];

void	input(int& num_of_words)
{
	cin>>num_of_words;
	
	for(int i=0;i<num_of_words;i++)
	{
		cin>>word[i];
		head[word[i][0]].push_back(i);
	}
	
	for(int i=0;i<num_of_words;i++)
	{
		vector<int>&	next_words = head[BACK_CHAR(word[i])];
		
		for(int j=0;j<next_words.size();j++)
		{
			if( i != next_words[j] )
			{
				connected[i].push_back(next_words[j]);
			}
		}
	}
}

int		get_dp(char first,int visited)
{
	int&	ret = dp[first][visited];
		
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	vector<int>&	current_words = head[first];
	
	for(int i=0;i<current_words.size();i++)
	{
		int&	index = current_words[i];
		string&	w = word[index];
		
		if( (visited&(1<<index)) == 0 )
		{
			ret = max(ret,get_dp(BACK_CHAR(w),visited|1<<index)+(int)w.length());
		}
	}
	
	return	ret;
}

int		main(void)
{
	int				N,max_score;
	
	input(N);
	
	init_dp('A',N);init_dp('E',N);init_dp('I',N);init_dp('O',N);init_dp('U',N);
	
	max_score = 0;
	
	max_score = max(max_score,get_dp('A',0));
	max_score = max(max_score,get_dp('E',0));
	max_score = max(max_score,get_dp('I',0));
	max_score = max(max_score,get_dp('O',0));
	max_score = max(max_score,get_dp('U',0));
	
	cout<<max_score<<'\n';
	
	return	0;
}
