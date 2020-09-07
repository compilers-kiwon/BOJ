#include <iostream>
#include <string>
#include <vector>

using namespace std;

void build_dic(int& dic_len,vector<string>& dic)
{
	cin>>dic_len;
	
	for(int i=1;i<=dic_len;i++)
	{
		string w;
		
		cin>>w;
		dic.push_back(w);
	}
}

void build_pw(string& pw,vector<string>& dic)
{
	int k;
	
	cin>>k;
	
	for(int i=1;i<=k;i++)
	{
		int p;
		
		cin>>p;
		pw += dic[p];
	}
}

int main(void)
{
	int T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int m,n;
		vector<string> dic;
		
		build_dic(m,dic);
		
		cin>>n;
		cout<<"Scenario #"<<i<<":\n";
		
		for(int j=1;j<=n;j++)
		{
			string pw;
			
			build_pw(pw,dic);
			cout<<pw<<'\n';
		}
		puts("");
	}
	
	return 0;
}
