#include    <iostream>

using namespace std;

#define TRUE        1
#define FALSE       0
#define MAX_SIZE    (2*5+1)

int is_chained(const char* state,int idx)
{
    if( idx == 1 )
    {
        return  TRUE;
    }

    return  ((state[idx-1]!=state[idx])
                    && is_chained(state,idx-1));
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    char    a[MAX_SIZE+1];

    cin>>N>>&a[1];
    cout<<(is_chained(a,2*N)?"Yes\n":"No\n");

    return  0;
}