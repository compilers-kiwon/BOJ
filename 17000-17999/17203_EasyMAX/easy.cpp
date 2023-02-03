#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  arr[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,Q;

    cin>>N>>Q;

    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }

    for(int i=1;i<=Q;i++)
    {
        int left,right;

        cin>>left>>right;

        if( right-1 < left )
        {
            cout<<"0\n";
            continue;
        }

        int sum = 0;

        for(int k=left;k<=right-1;k++)
        {
            sum += abs(arr[k+1]-arr[k]);
        }

        cout<<sum<<'\n';
    }

    return  0;
}