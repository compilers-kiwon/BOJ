#include	<iostream>
#include	<queue>

using namespace	std;

void	input(int& num_of_data,priority_queue<int>& difficulty)
{
	cin>>num_of_data;
	
	for(int i=1;i<=num_of_data;i++)
	{
		int	n;
		
		cin>>n;
		difficulty.push(n);
	}
}

int		get_num_of_ignored_data(int n)
{
	return	((n*10*15/100)+5)/10;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					n,ignored;
	priority_queue<int>	d;
	
	input(n,d);
	ignored = get_num_of_ignored_data(n);
	
	if( ignored*2 >= n )
	{
		cout<<"0\n";
		return	0;
	}
	
	int	sum,avg;
	
	for(int i=1;i<=ignored;i++)
	{
		d.pop();
	}
	
	for(sum=0;d.size()!=ignored;d.pop())
	{
		sum += d.top();
	}
	
	avg = (sum*10/(n-2*ignored)+5)/10;

	cout<<avg<<'\n';
	
	return	0;
}
