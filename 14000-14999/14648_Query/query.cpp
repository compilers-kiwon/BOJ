#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef long long int   int64;

static int64    arr[MAX_SIZE];

int64   get_sum(int from,int to)
{
    int64   ret = 0;

    for(int i=from;i<=to;i++)
    {
        ret += arr[i];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,q;

    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    for(int i=1;i<=q;i++)
    {
        int e,a,b,c,d;

        cin>>e;

        switch(e)
        {
            case    1:
                cin>>a>>b;
                cout<<get_sum(a,b)<<'\n';
                swap(arr[a],arr[b]);
                break;
            case    2:
                cin>>a>>b>>c>>d;
                cout<<get_sum(a,b)-get_sum(c,d)<<'\n';
                break;
            default:
                // do nothing
                break;
        }
    }

    return  0;
}