#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int E,N,cnt;

        cin>>E>>N;
        cnt = 0;

        for(int i=1;i<=N;i++)
        {
            int a;

            cin>>a;
            cnt += ((a>E)?1:0);
        }

        cout<<cnt<<'\n';
    }

    return  0;
}