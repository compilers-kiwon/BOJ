#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<map>

using namespace	std;

int						N,M;
vector<int>				s;
map<vector<int>,bool>	visited;

void		build_seq(vector<int>& seq)
{
	if( seq.size() == M && visited[seq] == false )
	{
		visited[seq] = true;
		
		for(int i=0;i<M;i++)
		{
			cout<<seq[i]<<' ';
		}
		cout<<'\n';
		
		return;
	}
	
	for(int i=0;i<N;i++)
	{
		if( s[i] != 0 )
		{
			seq.push_back(s[i]);
			s[i] = 0;
			
			build_seq(seq);
			
			s[i] = seq.back();
			seq.pop_back();
		}
	}
}

int			main(void)
{
	vector<int>	sub;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		s.push_back(n);
	}
	
	sort(s.begin(),s.end());
	
	build_seq(sub);
	
	return	0;
}
