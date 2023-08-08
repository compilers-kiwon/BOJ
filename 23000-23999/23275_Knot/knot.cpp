#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    bool    required[MAX_SIZE] = {false,};

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x;

        cin>>x;
        required[x] = true;
    }

    for(int i=1;i<n;i++)
    {
        int y;

        cin>>y;
        required[y] = false;
    }

    for(int i=1;i<MAX_SIZE;i++)
    {
        if( required[i] == true )
        {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}