#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>

using namespace	std;

void	add_bin_to_bin(vector<int>& bin1,vector<int>& bin2,vector<int>& result)
{
	int	carry;
	
	carry = 0;
	
	for(int i=bin1.size()-1;i>=0;i--)
	{
		int	b1,b2,tmp_val;
		
		b1 = bin1[i];
		b2 = bin2[i];
		
		tmp_val = b1+b2+carry;
		
		carry = tmp_val/2;
		tmp_val %= 2;
		
		result.push_back(tmp_val);
	}
	
	if( carry == 1 )
	{
		result.push_back(1);
	}
	else
	{
		for(;result.size()>0 && result.back()==0;result.pop_back());
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string		a,b;
		vector<int>	A,B,C;
		int			len_diff;
		
		cin>>a>>b;
		len_diff = abs((int)(a.length())-(int)(b.length()));
		
		if( len_diff != 0 )
		{
			if( a.length() < b.length() )
			{
				a.insert(0,len_diff,'0');
			}
			else
			{
				b.insert(0,len_diff,'0');
			}
		}
		
		for(int i=0;i<a.length();i++)
		{
			if( a[i] == '0' )
			{
				A.push_back(0);
			}
			else
			{
				A.push_back(1);
			}
			
			if( b[i] == '0' )
			{
				B.push_back(0);
			}
			else
			{
				B.push_back(1);
			}
		}
		
		add_bin_to_bin(A,B,C);
		
		if( C.size() == 0 )
		{
			C.push_back(0);
		}
		
		for(int i=C.size()-1;i>=0;i--)
		{
			cout<<C[i];
		}
		cout<<endl;
		
		T--;
	}
	return	0;
}
