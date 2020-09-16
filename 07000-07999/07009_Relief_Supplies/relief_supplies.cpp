#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

#define	get_next(i,s)	(((i)+1)%(s))

typedef	vector<int>	Pos;

int	N,T,B,S;

int	get_max_pos(Pos& p)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<p.size();i++)
	{
		ret = max(ret,p[i]);
	}
	
	return	ret;
}

int	simulate(void)
{
	vector<int>		boxes(T,B);
	vector<int>		cnt_of_supplies(N,0);
	map<int,Pos>	state;	// state[-boxes] = Pos
	
	int	ret;
	
	for(int t=0,p=0;boxes[t]!=0;t=get_next(t,T),p=get_next(p,N))
	{
		boxes[t]--;
		
		if( t == S-1 )
		{
			cnt_of_supplies[p]++;
		}	
	}
	
	for(int p=0;p<N;p++)
	{
		state[-cnt_of_supplies[p]].push_back(p+1);
	}
	
	map<int,Pos>::iterator	it;
	
	it = state.begin();
	
	if( it->second.size() != 1 )
	{
		ret = get_max_pos(it->second);
	}
	else
	{
		it++;
		ret = get_max_pos(it->second);
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	cnt,pos;
		
		cin>>N>>T>>B>>S;
		cout<<"Data Set "<<k<<":\n"<<simulate()<<"\n\n";
	}
	
	return	0;
}
