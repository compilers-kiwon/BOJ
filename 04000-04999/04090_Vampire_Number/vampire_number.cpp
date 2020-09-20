#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<vector>

using namespace	std;

#define	MAX_NUM		1000000

void	int2vec(int n,vector<int>& digits)
{
	for(;n>0;n/=10)
	{
		digits.push_back(n%10);
	}
	
	for(int h=0,t=digits.size()-1;h<t;h++,t--)
	{
		swap(digits[h],digits[t]);
	}
}

int		vec2int(vector<int>& digits,int from,int to)
{
	int	ret;
	
	ret = 0;
	
	for(int i=from;i<to;i++)
	{
		ret = ret*10+digits[i];
	}
	
	return	ret;
}

bool	is_vampire_number(vector<int>& digits,int v)
{
	bool	ret;
	
	ret = false;
	
	do{
		if( digits[0] == 0 )
		{
			continue;
		}
		
		for(int i=1;i<digits.size()-1&&ret==false;i++)
		{
			if( digits[i] == 0 )
			{
				continue;
			}
			
			int	a,b;
			
			a = vec2int(digits,0,i);
			b = vec2int(digits,i,digits.size());

			if( v == a*b )
			{
				ret = true;
			}
		}
	} while(ret!=true&&next_permutation(digits.begin(),digits.end()));
	
	return	ret;
}

void	get_vampire_numbers(vector<int>& v_num)
{
	for(int i=10;;i++)
	{
		vector<int>	d;
		
		int2vec(i,d);
		
		if( is_vampire_number(d,i) == true )
		{
			v_num.push_back(i);
			
			if( i > MAX_NUM )
			{
				break;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<int>	vampire_nums;
	
	get_vampire_numbers(vampire_nums);

	for(;;)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cout<<*(lower_bound(vampire_nums.begin(),vampire_nums.end(),N))<<'\n';
	}
	
	return	0;
}
