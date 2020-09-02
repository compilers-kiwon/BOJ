#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	10

bool	input(vector<string>& exp,string& appeared,bool* is_head)
{
	int		N,ptr;
	bool	used[0x100];
	
	cin>>N;
	
	if( N == 0 )
	{
		return	false;
	}
	
	fill(&used['A'],&used['Z'+1],false);
		
	for(int i=1;i<=N;i++)
	{
		string	w;
		
		cin>>w;
		exp.push_back(w);
		
		if( w.length()>1 )
		{
			is_head[w[0]] = true;
		}
		
		for(int j=0;j<w.length();j++)
		{
			char&	c = w[j];
			
			if( used[c] == false )
			{
				used[c] = true;
				appeared.push_back(c);
			}
		}
	}
	
	return	true;
}

int		str2int(string& str,int* table)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+table[str[i]];
	}
	
	return	ret;
}

void	count_of_available_exp(vector<string>& exp,string& used,int& cnt,int current_used_idx,
							   bool* used_number,int* char2int,bool* is_head)
{
	if( current_used_idx == used.length() )
	{
		int	left,right;

		left=0;
		
		for(int i=0;i<exp.size()-1;i++)
		{
			left += str2int(exp[i],char2int);
		}
		
		right = str2int(exp.back(),char2int);
		
		if( left == right )
		{
			cnt++;
		}
		
		return;
	}
	
	int	i;
	
	if( is_head[used[current_used_idx]] == true )
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	
	for(;i<MAX_SIZE;i++)
	{
		if( used_number[i] == false)	
		{
			used_number[i] = true;
			char2int[used[current_used_idx]] = i;
			
			count_of_available_exp(exp,used,cnt,current_used_idx+1,used_number,char2int,is_head);
			
			used_number[i] = false;
		}
	}
}

int		count_exp(vector<string>& words,string& appeared,bool* is_head)
{
	int		ret,char2int[0x100];
	bool	used_number[MAX_SIZE] = {false,false,false,false,false,false,false,false,false,false};
	
	ret = 0;
	count_of_available_exp(words,appeared,ret,0,used_number,char2int,is_head);
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		vector<string>	exp;
		string			used;
		bool			is_head[0x100];
		
		fill(&is_head[0],&is_head[0x100],false);
		
		if( input(exp,used,is_head) == false )
		{
			break;
		}
		
		cout<<count_exp(exp,used,is_head)<<'\n';
	}
	
	return	0;
}
