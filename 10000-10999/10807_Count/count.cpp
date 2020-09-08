#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int N;
    
    cin>>N;
    
    map<int,int> table;
    
    for(int i=1;i<=N;i++)
    {
        int n;
        
        cin>>n;
        table[n]++;
    }
    
    int v;
    
    cin>>v;
    cout<<table[v]<<endl;
    
    return 0;
}
