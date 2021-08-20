#include    <iostream>
#include    <algorithm>
#include    <vector>

using namespace std;

typedef long long int   int64;

int main(void)
{
    int             N;
    int64           min_size;
    vector<int64>   v;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int64   p;

        cin>>p;
        v.push_back(p*10);
    }

    sort(v.begin(),v.end());
    min_size = 2000000000000;

    for(int i=1;i<N-1;i++)
    {
        int64   left,right;

        left = (v[i]+v[i-1])/2;
        right = (v[i+1]+v[i])/2;
        
        min_size = min(min_size,right-left);
    }
    
    cout<<min_size/10<<'.'<<min_size%10<<'\n';

    return  0;
}