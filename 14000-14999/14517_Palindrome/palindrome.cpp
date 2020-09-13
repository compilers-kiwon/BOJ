#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	1000
#define	MOD(n)	((n)%10007)

int		palindrome_table[MAX_LEN][MAX_LEN];
string	str;

int		find_palindrome(int left,int right)
{
	if( left > right )
	{
		return	0;
	}
	
	if( palindrome_table[left][right] != -1 )
	{
		return	palindrome_table[left][right];
	}
	
	int	num_of_palindrome = 0;
	
	for(int i=left;i<right;i++)
	{
		if( str[i] == str[right] )
		{
			num_of_palindrome = num_of_palindrome+1+find_palindrome(i+1,right-1);
		}
	}
	
	num_of_palindrome = num_of_palindrome+1+find_palindrome(left,right-1);
	palindrome_table[left][right] = MOD(num_of_palindrome);
	
	return	palindrome_table[left][right];
}

int		main(void)
{
	int	len;
	
	cin>>str;
	len = str.length();
	
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			palindrome_table[i][j] = -1;
		}
	}
	
	cout<<find_palindrome(0,len-1)<<endl;
	
	return	0;
}
