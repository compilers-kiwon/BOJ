#include	<iostream>
#include	<queue>
#include	<vector>
#include	<stack>

using namespace	std;

#define	MAX_NUM_OF_SHELTERS	(5000+1)

vector<int>	height_of_shelter(MAX_NUM_OF_SHELTERS);
vector<int>	path[MAX_NUM_OF_SHELTERS];
vector<int>	answer(MAX_NUM_OF_SHELTERS,0);

priority_queue< pair<int, pair<int,int> > >	shelters;	// first : height , second < first:shelter, second:num_of_visits >

int		main(void)
{
	int	N,M,i;
	
	cin>>N>>M;
	
	for(i=1;i<=N;i++)
	{
		int	h;
		
		cin>>h;
		
		height_of_shelter[i] = h;
		shelters.push(make_pair(h,make_pair(i,1)));
	}
	
	for(i=1;i<=M;i++)
	{
		int	s1,s2,h1,h2;
		
		cin>>s1>>s2;
		
		h1 = height_of_shelter[s1];
		h2 = height_of_shelter[s2];
		
		if( h1 > h2 )
		{
			path[s1].push_back(s2);
		}
		else if( h1 < h2 )
		{
			path[s2].push_back(s1);
		}
	}
	
	//for(i=1;i<=N;i++)
	//{
	//	if( path[i].size() == 0 )
	//	{
	//		shelters.push(make_pair(height_of_shelter[i],make_pair(i,1)));
	//	}
	//}
	
	while( shelters.size() != 0 )
	{
		int			highest_shelter,path_len_of_highest_shelter,path_len;
				
		highest_shelter = shelters.top().second.first;
		path_len_of_highest_shelter = shelters.top().second.second;
		shelters.pop();
		
		//if( answer[highest_shelter] >= path_len_of_highest_shelter )
		if( answer[highest_shelter] > path_len_of_highest_shelter )
		{
			continue;
		}
		
		path_len = path_len_of_highest_shelter;
		answer[highest_shelter] = path_len;
		++path_len;
			
		for(i=0;i<path[highest_shelter].size();i++)
		{
			int	next_shelter;
			
			next_shelter = (path[highest_shelter])[i];
			
			if( answer[next_shelter] < path_len )
			{
				answer[next_shelter] = path_len;
				shelters.push(make_pair(height_of_shelter[next_shelter],make_pair(next_shelter,path_len)));
			}
		}		
	}
	
	for(i=1;i<=N;i++)
	{
		cout<<answer[i]<<endl;
	}
	
	return	0;
}
