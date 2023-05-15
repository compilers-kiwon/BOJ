#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)

static int  m,b[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }

    for(int i=1;i<=m;)
    {
        cout<<b[i]<<' ';
        i += b[i];
    }

    cout<<'\n';
    return  0;
}