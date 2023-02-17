#include	<iostream>
#include	<string>
#include	<vector>
#include	<set>

using namespace	std;

static int	N,M;
static vector<string> prefix;
static set<string>	words;

#define	TRUE	1
#define	FALSE	0

#define	is_found(i,s)		((i)!=(s).end())
#define	is_shorter(w,p)		((w).length()<(p).length())
#define	is_included(w,p)	((w).substr(0,(p).length())==(p))

int	input(void)
{
	cin>>N>>M;

	for(int i=1;i<=N;i++)
	{
		string	str;

		cin>>str;
		words.insert(str);
	}

	for(int i=1;i<=M;i++)
	{
		string	str;

		cin>>str;
		prefix.push_back(str);
	}

	return	0;
}

int	find_prefix_word(const string& p)
{
	set<string>::iterator	it = words.lower_bound(p);

	if( !is_found(it,words) || is_shorter(*it,p) )
	{
		return	FALSE;
	}

	return	(is_included(*it,p)?TRUE:FALSE);
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int	cnt = 0;

	input();

	for(int i=0;i<prefix.size();i++)
	{
		cnt += find_prefix_word(prefix[i]);
	}

	cout<<cnt<<'\n';

	return	0;
}