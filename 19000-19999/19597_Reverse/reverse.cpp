#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

typedef	pair<string,int>	State;	// first:str, second:0=>non-reversed,1=>reversed

void	input(vector<State>& arr)
{
	int	N;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		State	s;
		
		cin>>s.first;
		s.second = 0;
		
		arr.push_back(s);
	}
}

void	reverse_current(string& str,int& flag)
{
	for(int h=0,t=str.length()-1;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
	
	flag = ((flag==1)?0:1);
}

void	reverse_prev(vector<State>& s,int n)
{
	reverse_current(s[n].first,s[n].second);
	
	if( s[n-1].first > s[n].first )
	{
		reverse_prev(s,n-1);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		vector<State>	v;
		
		v.push_back(make_pair("A",0));
		input(v);
		
		for(int j=1;j<v.size();j++)
		{
			string&	str = v[j].first;
			string&	prev = v[j-1].first;
			int&	reversed = v[j].second;
			
			if( prev <= str )
			{
				continue;
			}
			
			reverse_current(str,reversed);
			
			if( prev <= str )
			{
				continue;
			}
			
			reverse_prev(v,j-1);
			reverse_current(str,reversed);
			
			if( prev <= str )
			{
				continue;
			}
			
			reverse_current(str,reversed);
		}
		
		for(int j=1;j<v.size();j++)
		{
			cout<<v[j].second;
		}
		cout<<'\n';
	}
	
	return	0;
}
