#include    <iostream>

using namespace std;

#define CLOCKWISE           0
#define COUNTERCLOCKWISE    1

int get_num_of_clicks(int d,int from,int to,int size)
{
    int ret;

    if( d == CLOCKWISE )
    {
        if( from > to )
        {
            ret = from-to;
        }
        else
        {
            ret = size-(to-from);
        }
    }
    else
    {
        if( from > to )
        {
            ret = size-(from-to);
        }
        else
        {
            ret = to-from;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int N,T1,T2,T3,c;

        cin>>N>>T1>>T2>>T3;

        if( N==0 && T1==0 && T2==0 && T3==0 )
        {
            break;
        }

        c = 2*N+(N-1)+N
            +get_num_of_clicks(COUNTERCLOCKWISE,T1,T2,N)
            +get_num_of_clicks(CLOCKWISE,T2,T3,N);
        
        cout<<c<<'\n';
    }

    return  0;
}