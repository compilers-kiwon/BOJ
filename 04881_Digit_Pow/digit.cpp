#include	<iostream>
#include	<set>
#include	<vector>

using namespace	std;

#define	INF	0x7FFFFFFF

int		get_next_num(int n)
{
	int	ret;
	
	for(ret=0;n>0;n/=10)
	{
		ret += (n%10)*(n%10);
	}
	
	return	ret;
}

void	get_cycle(int n,vector<int>& cycle)
{
	set<int>	nums;
	
	for(;nums.find(n)==nums.end();n=get_next_num(n))
	{
		cycle.push_back(n);
		nums.insert(n);
	}
}

int		get_seq_len(vector<int>& c1,vector<int>& c2)
{
	int	ret;
	
	ret = INF;
	
	for(int i=1;i<c1.size();i++)
	{
		for(int j=1;j<c2.size();j++)
		{
			if( c1[i] == c2[j] )
			{
				ret = min(ret,i+j);
			}
		}
	}
	
	return	ret;
}

int		get_shortest_len(int n1,int n2)
{
	vector<int>	n1_cycle;
	vector<int>	n2_cycle;
	
	n1_cycle.push_back(0);
	get_cycle(n1,n1_cycle);
	
	n2_cycle.push_back(0);
	get_cycle(n2,n2_cycle);
	
	return	min(INF,get_seq_len(n1_cycle,n2_cycle));
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	A,B,len;
		
		cin>>A>>B;
		
		if( A==0 && B==0 )
		{
			break;
		}
		
		len = get_shortest_len(A,B);
		
		if( len == INF )
		{
			cout<<A<<' '<<B<<" 0\n";
		}
		else
		{
			cout<<A<<' '<<B<<' '<<len<<'\n';
		}
	}
	
	return	0;
}
