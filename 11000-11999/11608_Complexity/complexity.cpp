#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	get_index(c)	((int)((c)-'a'))
#define	MAX_SIZE		26

int	get_complexity(string& s,int* count)
{
	int		ret,i;
	
	for(i=0;i<MAX_SIZE;i++)
	{
		count[i] = 0;
	}
	
	for(i=ret=0;i<s.length();i++)
	{
		int	index;
		
		index = get_index(s[i]);
		
		if( count[index] == 0 )
		{
			ret++;
		}
		
		count[index]++;
	}
	
	return	ret;
}

int		main(void)
{
	string	s;
	int		c,count[MAX_SIZE],min_time_of_eraser;
	
	priority_queue<int>	pq;
	
	cin>>s;
	c = get_complexity(s,count);
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		if( count[i] != 0 )
		{
			pq.push(-count[i]);
		}
	}
	
	for(min_time_of_eraser=0;c>2;c--)
	{
		min_time_of_eraser += -pq.top();
		pq.pop();
	}
	
	cout<<min_time_of_eraser<<'\n';
	
	return	0;
}
