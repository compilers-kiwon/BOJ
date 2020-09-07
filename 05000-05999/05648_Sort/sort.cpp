#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	char2int(c)	((int64)((c)-'0'))

typedef	long long int	int64;

int64	reverse_number(string& n)
{
	int64	result;
	int		i;
	
	for(i=n.length()-1,result=0;i>=0;i--)
	{
		result = result*10+char2int(n[i]);
	}
	
	return	result;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<int64>	pq;
	int						n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	num;
		
		cin>>num;
		pq.push(-reverse_number(num));
	}
	
	for(;!pq.empty();)
	{
		cout<<-pq.top()<<'\n';
		pq.pop();
	}
	
	return	0;
}
