#include	<iostream>
#include	<stack>

using namespace	std;

int	reverse_number(int n)
{
	stack<int>	st;
	int			value,d;
	
	for(;n>0;)
	{
		st.push(n%10);
		n /= 10;
	}
	
	for(value=0,d=1;st.size()!=0;st.pop(),d*=10)
	{
		value += st.top()*d;
	}
	return	value;
}

int	main(void)
{
	int	N,K,max_value,i,v;
	
	cin>>N>>K;
	max_value = 0;
	
	for(i=1,v=0;i<=K;i++)
	{
		v += N;
		max_value = max(max_value,reverse_number(v));
	}
	cout<<max_value<<endl;
	
	return	0;
}
