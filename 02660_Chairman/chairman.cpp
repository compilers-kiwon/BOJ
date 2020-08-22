#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_SIZE	4
#define	next(i)		(((i)+1)%MAX_SIZE)
#define	MAX_NUM		9999

int		get_clock_number(int* n,int ptr)
{
	int	ret,i;
	
	for(ret=i=0;i<MAX_SIZE;i++,ptr=next(ptr))
	{
		ret = ret*10+n[ptr];
	}
	
	return	ret;
}

int		get_min_number(int* n)
{
	int	ret,i;
	
	for(ret=MAX_NUM,i=0;i<MAX_SIZE;i++)
	{
		ret = min(ret,get_clock_number(n,i));
	}
			
	return	ret;
}

int		get_pos(set<int>& num_set,int n)
{
	set<int>::iterator	it;
	int					ret;
	
	for(it=num_set.begin(),ret=1;it!=num_set.end();it++,ret++)
	{
		if( *it == n )
		{
			break;
		}
	}
	
	return	ret;
}

void	get_all_num(set<int>& num_set,int* n,int idx)
{
	if( idx == MAX_SIZE )
	{
		num_set.insert(get_min_number(n));
		return;
	}
	
	for(int i=1;i<=9;i++)
	{
		n[idx] = i;
		get_all_num(num_set,n,idx+1);
	}
}

int		main(void)
{
	set<int>	num_set;
	int			n[MAX_SIZE];
	
	get_all_num(num_set,n,0);
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		cin>>n[i];
	}
	
	cout<<get_pos(num_set,get_min_number(n))<<'\n';
	
	return	0;
}
