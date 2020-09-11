#include	<iostream>
#include	<string>
#include	<set>
#include	<vector>

using namespace	std;

int	main(void)
{
	//cin.tie(NULL);
	//cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int c=1;c<=N;c++)
	{
		int				S,Q,cnt;
		vector<string>	search_engine;
		set<string>		query_set;
		
		cin>>S;getchar();
		
		for(int i=1;i<=S;i++)
		{
			string	engine;
			
			getline(cin,engine);
			search_engine.push_back(engine);
		}
		
		cin>>Q;getchar();
		cnt = 0;
		
		for(int i=1;i<=Q;i++)
		{
			string	q;
			
			getline(cin,q);
			
			if( query_set.size()==S-1 && query_set.find(q)==query_set.end() )
			{
				cnt++;
				query_set.clear();
			}
			query_set.insert(q);
		}
		
		cout<<"Case #"<<c<<": "<<cnt<<'\n';
	}
	
	return	0;
}
