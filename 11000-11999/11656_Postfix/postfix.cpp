#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

priority_queue<string> pq;
stack<string> answer;

int main(void)
{
	string word;
	int len;
	
	cin>>word;
	
	pq.push(word);
	len = word.length()-1;
	
	for(int i=0;i<len;i++)
	{
		word.erase(word.begin());
		pq.push(word);
	}
	
	while( pq.size() != 0 )
	{
		answer.push(pq.top());
		pq.pop();
	}
	
	while( answer.size() != 0 )
	{
		cout<<answer.top()<<endl;
		answer.pop();
	}
	
	return 0;
}
