#include    <iostream>

using namespace std;

#define MAX_SIZE    (63+1)

typedef long long int   int64;

static int  Q,cnt[MAX_SIZE];

int64  do_operation(void)
{
    int msb,carry;

    msb = -1;
    carry = 0;

    for(int i=0;i<MAX_SIZE;i++)
    {
        if( cnt[i]+carry != 0 )
        {
            msb = i;
            carry = (cnt[i]+carry)/2;
        }
    }

    return  (msb!=-1?1LL<<msb:0);
}

int get_msb_idx(int64 x)
{
    int i;

    for(i=0;((1LL<<i)&x)==0;i++);
    return  i;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   result = 0;

    cin>>Q;

    for(int i=1;i<=Q;i++)
    {
        int64   x;

        cin>>x;

        if( x != 0 )
        {
            if(x<0) cnt[get_msb_idx(-x)]--;
            else cnt[get_msb_idx(x)]++;

            result = do_operation();
        }

        cout<<result<<'\n';
    }

    return  0;
}