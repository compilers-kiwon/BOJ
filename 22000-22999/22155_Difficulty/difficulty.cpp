#include    <iostream>

using namespace std;

#define MAX_ALLOWED 2

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for(cin>>n;n>0;n--)
    {
        int i,f;

        cin>>i>>f;

        if( (i+f)<MAX_ALLOWED*2 && (i<=MAX_ALLOWED) && (f<=MAX_ALLOWED) )
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }

    return  0;
}