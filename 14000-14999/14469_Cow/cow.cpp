#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> Cow;

int main(void)
{
	int N;
	priority_queue<Cow> cow_pq;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int arrival_time,check_time;
		
		cin>>arrival_time>>check_time;
		cow_pq.push(make_pair(-arrival_time,check_time));
	}
	
	int start_time;
	
	start_time = 0;
	
	while( cow_pq.size() != 0 )
	{
		start_time = max(start_time,-cow_pq.top().first);
		start_time += cow_pq.top().second;
		cow_pq.pop();
	}
	cout<<start_time<<endl;
	
	return 0;
}
