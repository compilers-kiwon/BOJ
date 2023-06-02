#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    20

static int      n,m;
static string   s[MAX_SIZE],t[MAX_SIZE];

int get_name(void)
{
    cin>>n>>m;

    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<m;i++)cin>>t[i];

    return  0;
}

string  build_name(int year)
{
    return  s[(year-1)%n]+t[(year-1)%m];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int q;

    get_name();
    cin>>q;

    for(int i=1;i<=q;i++)
    {
        int y;

        cin>>y;
        cout<<build_name(y)<<'\n';
    }

    return  0;
}