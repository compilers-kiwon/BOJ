#include    <iostream>

using namespace std;

#define MAX_NUM 1000

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,prev,total;

    cin>>n;
    prev = MAX_NUM;
    total = 0;

    for(int i=1;i<=n;i++)
    {
        int p;

        cin>>p;

        total += max(0,p-prev);
        prev = min(prev,p);
    }

    cout<<total<<'\n';

    return  0;
}