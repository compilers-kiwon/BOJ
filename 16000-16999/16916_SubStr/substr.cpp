#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE		1000000
#define	get_index(c)	((int)((c)-'a'))

vector<int>	index[0x100];
int			S_table[26][MAX_SIZE],P_cnt[26];

void	init(string& S,string& P)
{
	cin>>S>>P;
	
	index[S[0]].push_back(0);
	S_table[get_index(S[0])][0] = 1;
	
	for(int i=1;i<S.length();i++)
	{
		index[S[i]].push_back(i);
		
		for(int c=0;c<=25;c++)
		{
			S_table[c][i] = S_table[c][i-1];
		}
		S_table[get_index(S[i])][i]++;
	}
	
	for(int i=0;i<P.length();i++)
	{
		P_cnt[get_index(P[i])]++;
	}
}

bool	is_sub_str(string& S,string& P)
{
	bool	result;
	int		sh,st,ph,pt;
	
	vector<int>&	heads = index[P[0]];
	
	result = false;
	
	for(int i=0;i<heads.size()&&result==false;i++)
	{
		sh = heads[i];
		st = sh+P.length()-1;
		
		if( st >= S.length() )
		{
			break;
		}
		
		ph = 0;
		pt = P.length()-1;
		
		bool	cnt_of_alphabet;
		
		cnt_of_alphabet = true;
		
		if( sh == 0 )
		{
			for(int c=0;c<=25;c++)
			{
				if( S_table[c][st] != P_cnt[c] )
				{
					cnt_of_alphabet = false;
					break;
				}
			}
		}
		else
		{
			for(int c=0;c<=25;c++)
			{
				int&	small = S_table[c][sh-1];
				int&	big = S_table[c][st];
				
				if( big-small != P_cnt[c] )
				{
					cnt_of_alphabet = false;
					break;
				}
			}
		}
		
		if( cnt_of_alphabet == false )
		{
			continue;
		}
		
		for(;sh<=st;sh++,st--,ph++,pt--)
		{
			if( S[sh]!=P[ph] || S[st]!=P[pt] )
			{
				break;
			}
		}
		
		if( sh > st )
		{
			result = true;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	string	S,P;
	
	init(S,P);
	cout<<is_sub_str(S,P)<<'\n';
	
	return	0;
}
