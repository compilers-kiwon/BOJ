#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,current,required;

    cin>>n;
    current = required = 0;

    for(int i=1;i<=n;i++)
    {
        int t;

        cin>>t;
        current += t;

        if( current < 0 )
        {
            required += -current;
            current = 0;
        }
    }

    cout<<required<<'\n';
    return  0;
}