#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Work;	// first:score,second:time
	
int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N,total_score;
	vector<Work>	w;
	
	cin>>N;
	total_score = 0;
	
	for(int t=1;t<=N;t++)
	{
		int	I,A,T;
		
		cin>>I;
		
		if( I == 1 )
		{
			cin>>A>>T;
			w.push_back(make_pair(A,T));
		}
		
		if( !w.empty() )
		{
			int& rt = w.back().second;
			
			if( (--rt) == 0 )
			{
				total_score += w.back().first;
				w.pop_back();
			}
		}
	}
	
	cout<<total_score<<'\n';
	
	return	0;
}
