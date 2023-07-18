#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define get_ranking(data,val) \
    (lower_bound((data).begin(),(data).end(),val)-(data).begin())

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> A,rank;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int n;

        cin>>n;

        A.push_back(n);
        rank.push_back(n);
    }

    rank.push_back(0);
    sort(rank.begin(),rank.end());

    for(int i=0;i<N;i++)
    {
        cout<<get_ranking(rank,A[i])<<'\n';
    }

    return  0;
}