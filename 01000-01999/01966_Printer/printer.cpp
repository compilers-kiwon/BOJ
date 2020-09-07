#include	<iostream>
#include	<queue>
#include	<map>

using namespace	std;

typedef	pair<int,bool>	Doc;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int				N,M,p;
		map<int,int>	priority;
		queue<Doc>		doc_q;
		
		cin>>N>>M;
		
		for(int i=0;i<M;i++)
		{
			cin>>p;
			++priority[-p];
			doc_q.push(make_pair(p,false));
		}
		
		cin>>p;
		++priority[-p];
		doc_q.push(make_pair(p,true));
		
		for(int i=M+1;i<N;i++)
		{
			cin>>p;
			++priority[-p];
			doc_q.push(make_pair(p,false));
		}
		
		map<int,int>::iterator	highest_priority = priority.begin();
		
		int	num_of_printed_doc = 0;
		
		while(1)
		{
			
			int	current_doc_priority;
			
			current_doc_priority = doc_q.front().first;
			
			if( -current_doc_priority == highest_priority->first )
			{
				++num_of_printed_doc;
				--(highest_priority->second);
				
				if( doc_q.front().second == true )
				{
					break;
				}
				
				doc_q.pop();
				
				if( highest_priority->second == 0 )
				{
					++highest_priority;
				}
			}
			else
			{
				doc_q.push(make_pair(current_doc_priority,doc_q.front().second));
				doc_q.pop();
			}
		}
		cout<<num_of_printed_doc<<endl;
		
		T--;
	}
	return	0;
}
