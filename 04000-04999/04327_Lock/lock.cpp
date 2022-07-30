#include    <iostream>

using namespace std;

#define CLOCKWISE           -1
#define COUNTER_CLOCKWISE   1

#define FULL    360
#define LOWER   -1
#define UPPER   40
#define DEGREE  9

int turn_dial(int from,int to,int offset)
{
    int ret = 0;

    for(;from!=to;ret+=DEGREE)
    {
        from += offset;

        switch(from)
        {
            case    LOWER:
                from = 39;
                break;
            case    UPPER:
                from = 0;
                break;
            default:
                // do nothing
                break;
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
        int s,p1,p2,p3;

        cin>>s>>p1>>p2>>p3;

        if( s==0 && p1==0 && p2==0 && p2==0 )
        {
            break;
        }

        cout<<FULL*2+turn_dial(s,p1,CLOCKWISE)+FULL*1
                +turn_dial(p1,p2,COUNTER_CLOCKWISE)+turn_dial(p2,p3,CLOCKWISE)<<'\n';
    }

    return  0;
}