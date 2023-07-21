#include    <iostream>

using namespace std;

#define INF 0x7FFFFFFF

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cur,cnt;

    cin>>N;
    cur = INF;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        int c;

        cin>>c;
        cnt += (c>cur)?1:0;
        cur = c;
    }

    cout<<cnt<<'\n';
    return  0;
}