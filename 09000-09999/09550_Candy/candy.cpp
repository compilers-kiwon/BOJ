#include <iostream>

using namespace std;

int main(void)
{
	int T;
	
	cin>>T;
	
	while(T>0)
	{
		int N,K,v,i;
		
		cin>>N>>K;
		
		for(i=1,v=0;i<=N;i++)
		{
			int c;
			
			cin>>c;
			v += c/K;
		}
		cout<<v<<endl;
		
		T--;
	}
	
	return 0;
}
