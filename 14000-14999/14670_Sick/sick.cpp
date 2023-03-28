#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    100
#define NONE        -1

static int  N,R;
static int  medicine[MAX_SIZE+1];

int read_medicines(void)
{
    fill(&medicine[0],&medicine[MAX_SIZE+1],NONE);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int e,n;

        cin>>e>>n;
        medicine[e] = n;
    }

    return  0;
}

int take_medicines(void)
{
    cin>>R;

    for(int i=1;i<=R;i++)
    {
        int         L;
        vector<int> buf;

        cin>>L;

        for(int j=1;j<=L;j++)
        {
            int S;

            cin>>S;

            if( medicine[S] != NONE )
            {
                buf.push_back(medicine[S]);
            }            
        }

        if( buf.size() != L )
        {
            cout<<"YOU DIED\n";
        }
        else
        {
            for(int j=0;j<L;j++)
            {
                cout<<buf[j]<<((j==(L-1))?'\n':' ');
            }
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_medicines();
    take_medicines();

    return  0;
}