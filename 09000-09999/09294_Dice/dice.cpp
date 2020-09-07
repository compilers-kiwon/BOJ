#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	vector<int>	Combination;

bool	is_equal(vector<int>& v1,vector<int>& v2)
{
	bool	ret;
	
	ret = true;
	
	for(int i=0;i<v1.size();i++)
	{
		if( v1[i] != v2[i] )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		get_sum(vector<int>& v)
{
	int	sum,i;
	
	for(i=sum=0;i<v.size();i++)
	{
		sum += v[i];
	}

	return	sum;	
}

void	dfs(int dice_index,int num_of_dice,int dice_size,
			vector<int>& n,int target_sum,vector<Combination>& s)
{
	if( dice_index > num_of_dice )
	{
		if( get_sum(n) == target_sum )
		{
			bool		found;
			vector<int>	tmp;
			
			found = false;
			
			tmp = n;
			sort(tmp.begin(),tmp.end());
			
			for(int i=0;i<s.size();i++)
			{
				if( is_equal(tmp,s[i]) == true )
				{
					found = true;
					break;
				}
			}
			
			if( found == false )
			{
				s.push_back(tmp);
			}
		}
		
		return;
	}
	
	for(int i=1;i<=dice_size;i++)
	{
		n.push_back(i);
		dfs(dice_index+1,num_of_dice,dice_size,n,target_sum,s);
		n.pop_back();
	}
}

int		main(void)
{
	int	c;
	
	cin>>c;
	
	for(int t=1;t<=c;t++)
	{
		int					n,m,s;
		vector<int>			numbers;
		vector<Combination>	set;
		
		cin>>n>>m>>s;
		dfs(1,n,m,numbers,s,set);
		
		cout<<"Case "<<t<<":\n";
		
		for(int i=0;i<set.size();i++)
		{
			vector<int>& n = set[i];
			
			cout<<'(';
			
			for(int j=0;j<n.size()-1;j++)
			{
				cout<<n[j]<<',';
			}
			cout<<n.back()<<")\n";
		}
	}
	
	return	0;
}
