#include	<iostream>
#include	<set>

using namespace	std;

void	sub_set(set<int>& A,set<int>& B,set<int>& result)
{
	set<int>::iterator	it1,it2;
	
	it1=A.begin();
	it2=B.begin();
	
	while( it1!=A.end() && it2!=B.end() )
	{
		if( *it1 < *it2 )
		{
			result.insert(*it1);
			it1++;
		}
		else if( *it1 > *it2 )
		{
			it2++;
		}
		else
		{
			it1++;it2++;
		}
	}
	
	for(;it1!=A.end();it1++)
	{
		result.insert(*it1);
	}
}

void	add_set(set<int>& A,set<int>& B,set<int>& result)
{
	set<int>::iterator	it1,it2;
	
	it1=A.begin();
	it2=B.begin();
	
	while( it1!=A.end() && it2!=B.end() )
	{
		if( *it1 < *it2 )
		{
			result.insert(*it1);
			it1++;
		}
		else if( *it1 > *it2 )
		{
			result.insert(*it2);
			it2++;
		}
		else
		{
			result.insert(*it1);
			it1++;it2++;
		}
	}
	
	for(;it1!=A.end();it1++)
	{
		result.insert(*it1);
	}
	
	for(;it2!=B.end();it2++)
	{
		result.insert(*it2);
	}
}

int		main(void)
{
	int			size_of_A,size_of_B;
	set<int>	A,B,A_sub_B,B_sub_A,final;
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>size_of_A>>size_of_B;
	
	for(int i=1;i<=size_of_A;i++)
	{
		int	n;
		
		cin>>n;
		A.insert(n);
	}
	
	for(int i=1;i<=size_of_B;i++)
	{
		int	n;
		
		cin>>n;
		B.insert(n);
	}
	
	sub_set(A,B,A_sub_B);
	sub_set(B,A,B_sub_A);
	add_set(A_sub_B,B_sub_A,final);
	
	cout<<final.size()<<'\n';
	
	return	0;
}
