#include	<iostream>
#include	<string>

using namespace	std;

bool	compare(string& big,string& small,int index,int len)
{
	bool	result;
	int		i;
	
	for(i=0,result=true;i<len;i++)
	{
		if( big[index+i] != small[i] )
		{
			result = false;
			break;
		}
	}
	return	result;
}

int		main(void)
{
	string	H,N;
	int		cnt;
	
	cin>>H>>N;
	cnt = 0;
	
	for(int i=0;i<=H.length()-N.length();i++)
	{
		if( H[i] == N[0] )
		{
			if( compare(H,N,i,N.length()) == true )
			{
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
