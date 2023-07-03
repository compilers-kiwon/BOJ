#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  N;
static struct{int X,L;char C;}  ribbon[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++) cin>>ribbon[i].X;
    for(int i=1;i<=N;i++) cin>>ribbon[i].L;
    for(int i=1;i<=N;i++) cin>>ribbon[i].C;

    return  0;
}

int simulate(void)
{
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if( abs(ribbon[i].X-ribbon[j].X)
                    <= ribbon[i].L+ribbon[j].L )
            {
                if( ribbon[i].C != ribbon[j].C )
                {
                    cout<<"YES\n"<<i<<' '<<j<<'\n';
                    return  0;
                }
            }
        }
    }

    cout<<"NO\n";
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    return  0;
}