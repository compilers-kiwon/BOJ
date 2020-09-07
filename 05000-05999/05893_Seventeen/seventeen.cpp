#include	<iostream>
#include	<vector>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

void	init(vector<int>& big,vector<int>& small)
{
	string	bin;
	
	cin>>bin;
	
	for(int i=1;i<=4;i++)
	{
		small.push_back(0);
	}
	
	for(int i=0;i<bin.length();i++)
	{
		int	n;
		
		n = char2int(bin[i]);
		big.push_back(n);
		small.push_back(n);
	}
	
	for(int i=1;i<=4;i++)
	{
		big.push_back(0);
	}
}

void	sum(vector<int>& big,vector<int>& small)
{
	int	i,carry;
	
	for(carry=0,i=big.size()-1;i>=0;i--)
	{
		int	tmp;
		
		tmp = big[i]+small[i]+carry;
		big[i] = tmp%2;
		carry = tmp/2;
	}
	
	if( carry == 1 )
	{
		big.insert(big.begin(),1);
	}
}

int		main(void)
{
	vector<int>	big,small;
	
	init(big,small);
	sum(big,small);
	
	for(int i=0;i<big.size();i++)
	{
		cout<<big[i];
	}
	cout<<endl;
	
	return	0;
}
