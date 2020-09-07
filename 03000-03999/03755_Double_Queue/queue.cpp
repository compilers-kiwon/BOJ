#include	<iostream>
#include	<map>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	map<int,int>	queue;	// queue[priority] = client
	
	for(bool stop=false;stop!=true;)
	{
		int	request,client,priority;
		
		map<int,int>::iterator			highest;
		map<int,int>::reverse_iterator	lowest;
		
		cin>>request;
		
		switch(request)
		{
			case	0:
				stop = true;
				break;
			case	1:
				cin>>client>>priority;
				queue[-priority] = client;
				break;
			case	2:
				if( queue.empty() )
				{
					cout<<"0\n";
				}
				else
				{
					highest = queue.begin();
					cout<<highest->second<<'\n';
					queue.erase(highest->first);
				}
				break;
			case	3:
				if( queue.empty() )
				{
					cout<<"0\n";
				}
				else
				{
					lowest = queue.rbegin();
					cout<<lowest->second<<'\n';
					queue.erase(lowest->first);
				}
				break;
			default:
				// do nothing
				break;
		}
	}
	
	return	0;
}
