#include	<iostream>
#include	<vector>
#include	<map>
#include	<string>

using namespace	std;

#define	a_pos	0
#define	g_pos	1
#define	t_pos	2
#define	c_pos	3
#define	MAX_DNA	4

#define	MAX_LEN	(60000+1)

typedef	vector<int>	Count;

int	dna_cnt[MAX_DNA][MAX_LEN];

int	count_dna(string& dna,map<Count,int>& cnt_table,int mcs_len)
{
	dna.insert(dna.begin(),' ');
	dna_cnt[a_pos][0] = dna_cnt[g_pos][0] = dna_cnt[t_pos][0] = dna_cnt[c_pos][0] = 0;
	
	for(int i=1;i<mcs_len;i++)
	{
		int	pos;
		
		switch(dna[i])
		{
			case	'A':
				pos = a_pos;
				break;
			case	'G':
				pos = g_pos;
				break;
			case	'T':
				pos = t_pos;
				break;
			case	'C':
				pos = c_pos;
				break;
			default:
				// do nothing
				break;
		}
		
		dna_cnt[a_pos][i] = dna_cnt[a_pos][i-1];
		dna_cnt[g_pos][i] = dna_cnt[g_pos][i-1];
		dna_cnt[t_pos][i] = dna_cnt[t_pos][i-1];
		dna_cnt[c_pos][i] = dna_cnt[c_pos][i-1];
		
		dna_cnt[pos][i]++;
	}
	
	int	max_cnt;
	
	max_cnt = 0;
	
	for(int i=mcs_len,j=0;i<dna.length();i++,j++)
	{
		int	pos;
		
		switch(dna[i])
		{
			case	'A':
				pos = a_pos;
				break;
			case	'G':
				pos = g_pos;
				break;
			case	'T':
				pos = t_pos;
				break;
			case	'C':
				pos = c_pos;
				break;
			default:
				// do nothing
				break;
		}
		
		dna_cnt[a_pos][i] = dna_cnt[a_pos][i-1];
		dna_cnt[g_pos][i] = dna_cnt[g_pos][i-1];
		dna_cnt[t_pos][i] = dna_cnt[t_pos][i-1];
		dna_cnt[c_pos][i] = dna_cnt[c_pos][i-1];
		
		dna_cnt[pos][i]++;
		
		Count	c(MAX_DNA);
		
		c[a_pos] = dna_cnt[a_pos][i]-dna_cnt[a_pos][j];
		c[g_pos] = dna_cnt[g_pos][i]-dna_cnt[g_pos][j];
		c[t_pos] = dna_cnt[t_pos][i]-dna_cnt[t_pos][j];
		c[c_pos] = dna_cnt[c_pos][i]-dna_cnt[c_pos][j];
		
		cnt_table[c]++;
		max_cnt = max(max_cnt,cnt_table[c]);
	}
	
	return	max_cnt;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		k;
		string	dna;
		
		map<Count,int> cnt_table;
		
		cin>>k>>dna;
		cout<<count_dna(dna,cnt_table,k)<<'\n';
		T--;
	}
	
	return	0;
}
