#include    <iostream>
#include    <string>

using namespace std;

#define TERMINATE   "#"

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  code;

        cin>>code;

        if( code == TERMINATE )
        {
            break;
        }

        int M,S,T;

        cin>>M>>S>>T;

        for(int i=1;i<=T;i++)
        {
            char    t;
            int     n;

            cin>>t>>n;

            switch(t)
            {
                case    'S':
                    S = max(0,S-n);
                    break;
                case    'R':
                    S = min(M,S+n);
                    break;
                default:
                    // do nothing
                    break;
            }
        }

        cout<<code<<' '<<S<<'\n';
    }

    return  0;
}