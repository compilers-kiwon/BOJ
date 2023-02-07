#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

int used_buckets[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,max_buckets;

    cin>>N;
    max_buckets = 0;

    for(int i=1;i<=N;i++)
    {
        int s,t,b;

        cin>>s>>t>>b;

        for(int j=s;j<=t;j++)
        {
            max_buckets = max(max_buckets,
                        (used_buckets[j]+=b));
        }
    }

    cout<<max_buckets<<'\n';

    return  0;
}