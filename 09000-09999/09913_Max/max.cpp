#include    <iostream>

using namespace std;

#define MAX_NUM 1000

static int  N,cnt[MAX_NUM+1];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int highest_frequency =0;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int n;

        cin>>n;
        highest_frequency = max(highest_frequency,++cnt[n]);
    }

    cout<<highest_frequency<<'\n';
    return  0;
}