#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Line;

int main(void)
{
	cin.sync_with_stdio(false);
	
	int N,total_len;
	vector<Line> line;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int X,Y;
		
		cin>>X>>Y;
		line.push_back(make_pair(X,Y));
	}
	
	sort(line.begin(),line.end());
	
	Line current;
	
	current = make_pair(0,0);
	total_len = 0;
	
	for(int i=0;i<N;i++)
	{
		int s,e;
		
		s = line[i].first;
		e = line[i].second;
		
		if( s <= current.second )
		{
			current.second = max(e,current.second);
		}
		else
		{
			total_len += current.second-current.first;
			current = line[i];
		}
	}
	total_len += current.second-current.first;
	
	cout<<total_len<<'\n';
	
	return 0;
}
