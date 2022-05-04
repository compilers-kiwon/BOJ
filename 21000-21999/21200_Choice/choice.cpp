#include    <iostream>
#include    <vector>

using namespace std;

bool    find_selected_card(int selected)
{
    int     n;
    bool    ret = false;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int c;

        cin>>c;

        if( c == selected )
        {
            ret = true;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,P,S;

    cin>>N>>P>>S;

    for(int i=1;i<=S;i++)
    {
        cout<<(find_selected_card(P)?"KEEP":"REMOVE")<<'\n';
    }

    return  0;
}