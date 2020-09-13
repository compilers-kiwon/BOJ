#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>
#include	<algorithm>

using namespace	std;

void	init(string* num_table)
{
	num_table[0] = "ZERO";	// Z
	num_table[6] = "XSI";	// X
	num_table[8] = "GEIHT";	// G
	num_table[2] = "WTO";	// W
	num_table[4] = "UFOR";	// U
	num_table[5] = "FIVE";	// F
	num_table[7] = "VSEEN";	// V
	num_table[3] = "THREE";	// T
	num_table[9] = "INNE";	// I
	num_table[1] = "ONE";	// O
}

void	remove_number(vector<int>& cnt,int n,string* num_table,vector<int>& number)
{
	char&	represent = num_table[n][0];
	int		num_of_number;
	
	num_of_number = cnt[represent];
	
	for(int i=0;i<num_table[n].length();i++)
	{
		char&	c = num_table[n][i];
		
		cnt[c] -= num_of_number;
	}
	
	for(int i=1;i<=num_of_number;i++)
	{
		number.push_back(n);
	}
}

int		input(vector<int>& cnt)
{
	string	str;
	
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		cnt[str[i]]++;
	}
	
	return	str.length();
}


int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		T;
	string	num_table[10];
	
	cin>>T;
	init(num_table);
	
	for(int i=1;i<=T;i++)
	{
		vector<int>	cnt(0x100,0);
		vector<int>	number;
		int			str_len;
		
		cout<<"Case #"<<i<<": ";
		
		str_len = input(cnt);
		
		remove_number(cnt,0,num_table,number);
		remove_number(cnt,6,num_table,number);
		remove_number(cnt,8,num_table,number);
		remove_number(cnt,2,num_table,number);
		remove_number(cnt,4,num_table,number);
		remove_number(cnt,5,num_table,number);
		remove_number(cnt,7,num_table,number);
		remove_number(cnt,3,num_table,number);
		remove_number(cnt,9,num_table,number);
		remove_number(cnt,1,num_table,number);
		
		sort(number.begin(),number.end());
				
		for(int j=0;j<number.size();j++)
		{
			cout<<number[j];
		}
		cout<<'\n';
	}
	
	return	0;
}
