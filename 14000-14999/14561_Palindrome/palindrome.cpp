#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned long long	uint64;

bool	is_palindrome(vector<int>& base_num)
{
	bool	result;
	int		head,tail;
	
	for(head=0,tail=base_num.size()-1,result=true;head<tail;head++,tail--)
	{
		if( base_num[head] != base_num[tail] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

void	convert(uint64 A,int b,vector<int>& base_num)
{
	for(;A!=0;A/=b)
	{
		base_num.push_back(A%b);
	}
}

int		main(void)
{
	uint64		A;
	int			n,T;
	
	cin>>T;
	
	while(T>0)
	{
		vector<int>	c;
		
		cin>>A>>n;
		convert(A,n,c);
		cout<<is_palindrome(c)<<'\n';
		
		T--;
	}
	
	return	0;
}
