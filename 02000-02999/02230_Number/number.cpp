#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

typedef long long int   int64;

#define INF 0x7FFFFFFFFFFFFFFF

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   N,M,min_diff;
    
    vector<int64>   A;
    vector<int64>::iterator it;

    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        int64   n;

        cin>>n;
        A.push_back(n);
    }

    min_diff = INF;
    sort(A.begin(),A.end());

    for(it=A.begin();it<A.end();it++)
    {
        int64   small = *it;
        int64   big = small+M;
        
        vector<int64>::iterator n = 
                lower_bound(it,A.end(),big);

        if( n != A.end() )
        {
            min_diff = min((*n)-small,min_diff);
        }
    }

    cout<<min_diff<<'\n';
    return  0;
}