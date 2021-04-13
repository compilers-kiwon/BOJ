#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>
#include	<map>

using namespace	std;

typedef	vector<string>	Word_Len;

map<int,Word_Len>	dic[0x100];
vector<string>		all_words;

void	input(void)
{
	for(;;)
	{
		string	w;
		
		cin>>w;
		
		if( w.empty() )
		{
			break;
		}
		
		all_words.push_back(w);
		dic[w[0]][w.length()].push_back(w);
	}
}

bool	is_compound_word(const string& w)
{
	for(int i=1;i<w.length();i++)
	{
		string	h,t;
		
		h = w.substr(0,i);
		t = w.substr(i,w.length()-i);
		
		Word_Len&	d1 = dic[h[0]][h.length()];
		Word_Len&	d2 = dic[t[0]][t.length()];
		
		if( d1.empty() || d2.empty() )
		{
			continue;
		}
		
		if( binary_search(d1.begin(),d1.end(),h) &&	binary_search(d2.begin(),d2.end(),t) )
		{
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=0;i<all_words.size();i++)
	{
		if( is_compound_word(all_words[i]) == true )
		{
			cout<<all_words[i]<<'\n';
		}
	}
	
	return	0;
}
