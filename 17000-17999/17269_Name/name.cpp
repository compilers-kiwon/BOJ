#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	get_index(c)	((int)((c)-'A'))
#define	MAX_OPERATIONS	200

const int	value[26] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};

void	get_value(vector<int>& in,vector<int>& out)
{
	for(int i=1;i<in.size();i++)
	{
		out.push_back((in[i-1]+in[i])%10);
	}
}

void	merge_name(string& n1,string& n2,string& ret)
{
	int	n1_index,n2_index;
	
	for(n1_index=n2_index=0;n1_index<n1.length()&&n2_index<n2.length();n1_index++,n2_index++)
	{
		ret.push_back(n1[n1_index]);
		ret.push_back(n2[n2_index]);
	}
	
	for(;n1_index<n1.length();n1_index++)
	{
		ret.push_back(n1[n1_index]);
	}
	
	for(;n2_index<n2.length();n2_index++)
	{
		ret.push_back(n2[n2_index]);
	}
}

int		main(void)
{
	int		N,M;
	string	A,B,C;
	
	cin>>N>>M>>A>>B;
	
	merge_name(A,B,C);
	
	vector<int>	result[MAX_OPERATIONS+1];
	
	for(int i=0;i<C.length();i++)
	{
		result[0].push_back(value[get_index(C[i])]);
	}
	
	for(int i=1;;i++)
	{
		get_value(result[i-1],result[i]);
		
		if( result[i].size() == 2 )
		{
			if( result[i][0] != 0 )
			{
				cout<<result[i][0];
			}
			cout<<result[i][1]<<"%\n";
			
			break;
		}
	}
	
	return	0;
}
