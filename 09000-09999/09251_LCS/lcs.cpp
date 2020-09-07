#include	<iostream>
#include	<string>

using namespace std;

#define	MAX_LEN	(1000+1)

int	table[MAX_LEN][MAX_LEN];

int	main(void)
{
	string	str1,str2;
	
	cin>>str1>>str2;
	str1.insert(0," ");str2.insert(0," ");
	
	int	row_len,col_len;
	
	row_len = str1.length()-1;
	col_len = str2.length()-1;
	
	for(int i=1;i<=row_len;i++)
	{
		for(int j=1;j<=col_len;j++)
		{
			if( str1[i] == str2[j] )
			{
				table[i][j] = table[i-1][j-1]+1;
			}
			else
			{
				table[i][j] = max(table[i-1][j],table[i][j-1]);
			}
		}
	}
	cout<<table[row_len][col_len]<<endl;
	
	return	0;
}
