#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  me;
    int     N,cnt;

    cin>>me>>N;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        string  f;

        cin>>f;
        cnt += ((me==f)?1:0);
    }

    cout<<cnt<<'\n';

    return  0;
}