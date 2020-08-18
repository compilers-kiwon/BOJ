#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	pair<char,int>		Key;
typedef	pair<int,string>	Encrypted;

string	key,encrypted;

int	main(void)
{
	cin>>key>>encrypted;
	
	vector<Key>			key_arr;
	vector<Encrypted>	en;
	
	int	i,j,k;
	
	for(i=0;i<key.length();i++)
	{
		key_arr.push_back(make_pair(key[i],i));
	}
	
	sort(key_arr.begin(),key_arr.end());
	
	for(i=k=0;i<key_arr.size();i++,k+=encrypted.length()/key.length())
	{
		string	tmp;
		
		for(j=0;j<encrypted.length()/key.length();j++)
		{
			tmp.push_back(encrypted[k+j]);
		}
		
		en.push_back(make_pair(key_arr[i].second,tmp));
	}
	
	sort(en.begin(),en.end());
	
	for(i=0;i<encrypted.length()/key.length();i++)
	{
		for(j=0;j<en.size();j++)
		{
			cout<<en[j].second[i];
		}
	}
	puts("");
	
	return	0;
}
