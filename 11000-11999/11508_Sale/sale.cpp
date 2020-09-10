#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_sum_of_cost(vector<int>& cost)
{
	int i,sum;
	
	for(i=cost.size()-1,sum=0;i-2>=0;i-=3)
	{
		sum += cost[i]+cost[i-1];
	}
	
	for(;i>=0;i--)
	{
		sum += cost[i];
	}
	
	return sum;
}

int main(void)
{
	int N;
	vector<int> c;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int n;
		
		cin>>n;
		c.push_back(n);
	}
	
	sort(c.begin(),c.end());
	cout<<get_sum_of_cost(c)<<endl;
	
	return 0;
}
