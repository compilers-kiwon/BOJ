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
/*    switch(x)
    {
        case 1LL<<0:return 0;
        case 1LL<<1:return 1;
        case 1LL<<2:return 2;
        case 1LL<<3:return 3;
        case 1LL<<4:return 4;
        case 1LL<<5:return 5;
        case 1LL<<6:return 6;
        case 1LL<<7:return 7;
        case 1LL<<8:return 8;
        case 1LL<<9:return 9;
        case 1LL<<10:return 10;
        case 1LL<<11:return 11;
        case 1LL<<12:return 12;
        case 1LL<<13:return 13;
        case 1LL<<14:return 14;
        case 1LL<<15:return 15;
        case 1LL<<16:return 16;
        case 1LL<<17:return 17;
        case 1LL<<18:return 18;
        case 1LL<<19:return 19;
        case 1LL<<20:return 20;
        case 1LL<<21:return 21;
        case 1LL<<22:return 22;
        case 1LL<<23:return 23;
        case 1LL<<24:return 24;
        case 1LL<<25:return 25;
        case 1LL<<26:return 26;
        case 1LL<<27:return 27;
        case 1LL<<28:return 28;
        case 1LL<<29:return 29;
        case 1LL<<30:return 30;
        case 1LL<<31:return 31;
        case 1LL<<32:return 32;
        case 1LL<<33:return 33;
        case 1LL<<34:return 34;
        case 1LL<<35:return 35;
        case 1LL<<36:return 36;
        case 1LL<<37:return 37;
        case 1LL<<38:return 38;
        case 1LL<<39:return 39;
        case 1LL<<40:return 40;
        case 1LL<<41:return 41;
        case 1LL<<42:return 42;
        case 1LL<<43:return 43;
        case 1LL<<44:return 44;
        case 1LL<<45:return 45;
        case 1LL<<46:return 46;
        case 1LL<<47:return 47;
        case 1LL<<48:return 48;
        case 1LL<<49:return 49;
        case 1LL<<50:return 50;
        case 1LL<<51:return 51;
        case 1LL<<52:return 52;
        case 1LL<<53:return 53;
        case 1LL<<54:return 54;
        case 1LL<<55:return 55;
        case 1LL<<56:return 56;
        case 1LL<<57:return 57;
        case 1LL<<58:return 58;
        case 1LL<<59:return 59;
        case 1LL<<60:return 60;
        case 1LL<<61:return 61;
        case 1LL<<62:return 62;
        case 1LL<<63:return 63;
    }

    return  -1;
*/
    int i;

    for(i=0;((1LL<<i)&x)==0;i++);
    return  i;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   prev_result = 0;

    cin>>Q;

    for(int i=1;i<=Q;i++)
    {
        int64   x;

        cin>>x;

        if( x != 0 )
        {
            if( x < 0 )
            {
                //cout<<"SUB\n";
                cnt[get_msb_idx(-x)]--;
            }
            else
            {
                //cout<<"ADD\n";
                cnt[get_msb_idx(x)]++;
            }

            cout<<(prev_result=do_operation())<<'\n';
        }
        else
        {
            cout<<prev_result<<'\n';
        }
    }

    return  0;
}