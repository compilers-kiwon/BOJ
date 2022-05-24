#include    <iostream>

using namespace std;

#define TBD -1

bool    is_ascending_order(int size,int& erased_number)
{
    int expected_number = 1;

    for(int i=1;i<=size;i++)
    {
        int current_number;

        cin>>current_number;

        if( current_number != expected_number )
        {
            if( erased_number != TBD )
            {
                return  false;
            }
            else
            {
                erased_number = expected_number;

                if( ++expected_number != current_number )
                {
                    return  false;
                }
            }
        }

        expected_number++;
    }

    if( erased_number == TBD )
    {
        erased_number = expected_number;
    }
    
    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,m,erased_number;

    cin>>n>>m;
    erased_number = TBD;

    if( n-1==m && is_ascending_order(m,erased_number)==true )
    {
        cout<<"Yes\n"<<erased_number<<'\n';
    }
    else
    {
        cout<<"No\n";
    }

    return  0;
}