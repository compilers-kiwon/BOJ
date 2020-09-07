#include	<iostream>
#include	<string>

using namespace	std;

int		get_diff(string& str1,string& str2,int str2_from)
{
	int diff = 0;
	
	for(int i=0;i<str1.length();i++)
	{
		if( str1[i] != str2[i+str2_from] )
		{
			diff++;
		}
	}
	return	diff;
}

int		main(void)
{
	string			A,B;
	int				min_diff;
	
	cin>>A>>B;
	
	min_diff = 50;
	
	for(int i=0;i<=B.length()-A.length();i++)
	{
		int tmp;
		
		tmp = get_diff(A,B,i);
		
		if( min_diff > tmp )
		{
			min_diff = tmp;
		}
	}
	
	cout<<min_diff<<endl;
	
	return	0;
}
