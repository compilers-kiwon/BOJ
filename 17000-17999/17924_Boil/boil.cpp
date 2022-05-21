#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_TIME    1000

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Time;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    bool    found = false;
    Time    t[MAX_SIZE];

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>t[i].first>>t[i].second;
    }

    for(int i=0;i<=MAX_TIME;i++)
    {
        bool    boiled = true;

        for(int j=1;j<=N;j++)
        {
            if( IN_RANGE(t[j].first,i,t[j].second) == false )
            {
                boiled = false;
                break;
            }
        }

        if( boiled == true )
        {
            found = true;
            break;
        }
    }

    if( found == true )
    {
        cout<<"gunilla has a point\n";
    }
    else
    {
        cout<<"edward is right\n";
    }

    return  0;
}