#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int a,b,S,rest,n;
        int big,small,num_of_big,num_of_small;

        cin>>a>>b>>S;
        
        big = max(a,b);
        small = min(a,b);

        num_of_big = S/big;
        num_of_small = (S%big)/small;

        bool    found = false;

        for(n=S-(num_of_big*big+num_of_small*small);;)
        {
            int current = num_of_big*big+num_of_small*small;

            if( current == S )
            {
                found = true;
                break;
            }

            if( num_of_big == 0 )
            {
                break;
            }

            num_of_big--;
            num_of_small = (S-num_of_big*big)/small;

            if( (S-(num_of_big*big+num_of_small*small)) == n )
            {
                break;
            }
        }

        if( found == false )
        {
            cout<<"Impossible\n";
            continue;
        }

        if( big == a )
        {
            cout<<num_of_big<<' '<<num_of_small<<'\n';
        }
        else
        {
            cout<<num_of_small<<' '<<num_of_big<<'\n';
        }
    }

    return  0;
}