#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAX_NUM_OF_WORDS (1000+1)

int main(void)
{
	int T;
	
	cin>>T;
	
	while(T>0)
	{
		int n;
		string words[MAX_NUM_OF_WORDS];
		map<string,int> first_key;
		map<int,int> second_key;
		
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			string w;
			
			cin>>w;
			first_key[w] = i;
		}
		
		for(int i=1;i<=n;i++)
		{
			string w;
			
			cin>>w;
			second_key[i] = first_key[w];
		}
		
		for(int i=1;i<=n;i++)
		{
			cin>>words[second_key[i]];
		}
		
		for(int i=1;i<=n;i++)
		{
			cout<<words[i]<<' ';
		}
		cout<<'\n';
		
		T--;
	}
	
	return 0;
}
