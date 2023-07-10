#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

static int  cnt[MAX_SIZE];

int input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=2*N-1;i++)
    {
        int A;

        cin>>A;
        cnt[A]++;
    }

    return  N;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N = input();

    for(int i=1;i<=N;i++)
    {
        if( cnt[i] == 1 )
        {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}