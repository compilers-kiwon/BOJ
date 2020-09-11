#include	<iostream>
#include	<string>
#include	<queue>
#include	<set>

using namespace	std;

#define	MAX_STR_LEN	50

#define	HEAD(str)	((str)[0])
#define	TAIL(str)	((str)[(str).length()-1])

set<string>	hash_table[MAX_STR_LEN];
string		S,T;

void	reverse(string& str)
{
	for(int h=0,t=str.length()-1;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
}

bool	trace_back(void)
{
	queue<string>	str_q;
	bool			result;
	
	str_q.push(T);
	result = false;
	
	while( !str_q.empty() )
	{
		string	current;
		
		current = str_q.front();
		str_q.pop();
		
		if( current.length() == S.length() )
		{
			if( current == S )
			{
				result = true;
				break;
			}
			continue;
		}
		
		char	head,tail;
		
		head = HEAD(current);
		tail = TAIL(current);
		
		if( tail == 'A' )
		{
			current.erase(current.length()-1,1);
			
			set<string>&	s = hash_table[current.length()];
			
			if( s.find(current) != s.end() )
			{
				// do nothing
			}
			else
			{
				s.insert(current);
				str_q.push(current);
			}
			
			current.push_back(tail);
		}
		
		if( head == 'B' )
		{
			reverse(current);
			current.erase(current.length()-1,1);
			
			set<string>&	s = hash_table[current.length()];
			
			if( s.find(current) != s.end() )
			{
				// do nothing
			}
			else
			{
				s.insert(current);
				str_q.push(current);
			}
		}
	}
	
	return	result;
}

int		main(void)
{
	cin>>S>>T;
	cout<<trace_back()<<endl;
	
	return	0;
}
