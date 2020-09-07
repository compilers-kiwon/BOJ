#include	<iostream>
#include	<string>

using namespace	std;

const string	number = "0123456789";

void	reverse_str(string& n)
{
	for(int h=0,t=n.length()-1;h<t;h++,t--)
	{
		swap(n[h],n[t]);
	}
}

void	bit_flip(string& base2,int pos)
{
	if( base2[pos] == '1' )
	{
		base2[pos] = '0';
	}
	else
	{
		base2[pos] = '1';
	}
}

int		base2_to_base3(string& in,string& out)
{
	int	n,i,ret;
	
	for(i=n=0;i<in.length();i++)
	{
		n = n*2+((in[i]=='1')?1:0);
	}
	
	ret = n;
	
	for(;n!=0;n/=3)
	{
		out.push_back(number[n%3]);
	}
	
	return	ret;
}

int		get_num_of_difference(string& a,string& b)
{
	int	ret,i;
	
	for(i=ret=0;ret<2&&i<a.length();i++)
	{
		if( a[i] != b[i] )
		{
			ret++;
		}
	}
	
	return	ret;
}

int		main(void)
{
	string	b2,b3;
	int		i,N;
	
	cin>>b2>>b3;
	reverse_str(b3);
	
	if( b2[0] == '1' )
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	
	for(;i<b2.length();i++)
	{
		string	correct_b3;
		
		bit_flip(b2,i);
		N = base2_to_base3(b2,correct_b3);
		
		if( correct_b3.length()==b3.length() 
			&& get_num_of_difference(correct_b3,b3) == 1 )
		{
			break;
		}
		
		bit_flip(b2,i);
	}
	
	cout<<N<<'\n';
	
	return	0;
}
