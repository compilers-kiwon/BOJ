#include    <iostream>

using namespace std;

#define PAR(n)  ((n)%2==1?2:3)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,total;

    cin>>N;
    total = 0;

    for(int i=1;i<=N;i++)
    {
        int p;

        cin>>p;
        total += min(p,7)-PAR(i);
    }

    cout<<total<<'\n';

    return  0;
}