#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>
#include	<map>

using namespace	std;

typedef	long long int	int64;

#define	char2int64(c)		((int64)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

bool	three_is_found(int64 n)
{
	for(;n>0;n/=10)
	{
		if( n%10 == 3 )
		{
			return	true;
		}
	}
	
	return	false;
}

void	do_operation(vector<int64>& v,int num_idx,
					 int64 prev_result,map<int64,int>& count)
{
	if( num_idx == v.size() )
	{
		if( three_is_found(prev_result) == true )
		{
			count[prev_result]++;
		}
		
		return;
	}
	
	do_operation(v,num_idx+1,prev_result+v[num_idx],count);
	do_operation(v,num_idx+1,prev_result*v[num_idx],count);
	do_operation(v,num_idx+1,abs(prev_result-v[num_idx]),count);
	
	if( v[num_idx] != 0 )
	{
		do_operation(v,num_idx+1,prev_result/v[num_idx],count);
	}
}

int64	str2int64(string& str)
{
	int64	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+char2int64(str[i]);
	}
	
	return	ret;
}

void	get_numbers(string& str,vector<int64>& v)
{
	string	number;
	
	for(int i=0;i<str.length();i++)
	{
		if( !IN_RANGE('0',str[i],'9') )
		{
			if( number.length() != 0 )
			{
				v.push_back(str2int64(number));
				number.clear();
			}
		}
		else
		{
			number.push_back(str[i]);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string			in;
		map<int64,int>	cnt;
		
		getline(cin,in);
		
		if( in == "#" )
		{
			break;
		}
		
		vector<int64>	numbers;
		
		in.push_back(' ');
		get_numbers(in,numbers);
		
		do_operation(numbers,1,numbers[0],cnt);
		
		if( cnt.size() != 0 )
		{
			int		max_cnt;
			int64	max_cnt_number;
			
			map<int64,int>::iterator	it;
			
			for(it=cnt.begin(),max_cnt=0;it!=cnt.end();it++)
			{
				if( max_cnt <= it->second )
				{
					max_cnt = it->second;
					max_cnt_number = it->first;
				}
			}
			
			cout<<max_cnt_number<<'\n';
		}
		else
		{
			cout<<"No result\n";
		}
	}
	
	return	0;
}
