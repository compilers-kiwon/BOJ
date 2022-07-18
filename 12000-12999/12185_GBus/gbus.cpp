#include    <iostream>

using namespace std;

#define MAX_SIZE    5000

void    build_map(int num_of_buses[])
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int A,B;

        cin>>A>>B;

        for(int j=A;j<=B;j++)
        {
            num_of_buses[j]++;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int b[MAX_SIZE+1],P;

        fill(&b[1],&b[MAX_SIZE+1],0);
        build_map(b);

        cin>>P;
        cout<<"Case #"<<t<<": ";

        for(int i=1;i<=P;i++)
        {
            int C;

            cin>>C;
            cout<<b[C]<<' ';
        }

        cout<<'\n';
    }

    return  0;
}