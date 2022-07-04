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
        int A,B,K,cnt;

        cin>>A>>B>>K;
        cnt = 0;

        for(int a=0;a<A;a++)
        {
            for(int b=0;b<B;b++)
            {
                if( (a&b) < K )
                {
                    cnt++;
                }
            }
        }

        cout<<"Case #"<<t<<": "<<cnt<<'\n';
    }

    return  0;
}