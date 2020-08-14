#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	TABLE_SIZE		26
#define	GET_INDEX(c)	((int)((c)-'a'))

int		table1[TABLE_SIZE],table2[TABLE_SIZE];
string	word1,word2;

void	build_table(string& w,int* t)
{
	for(int i=0;i<w.length();i++)
	{
		t[GET_INDEX(w[i])]++;
	}
}

int		main(void)
{
	cin>>word1>>word2;
	
	build_table(word1,table1);
	build_table(word2,table2);
	
	int	cnt,i;
	
	for(cnt=0,i=GET_INDEX('a');i<=GET_INDEX('z');i++)
	{
		cnt += abs(table1[i]-table2[i]);
	}
	cout<<cnt<<endl;
	
	return	0;
}
