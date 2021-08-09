#include    <iostream>

using namespace std;

#define MAX_SIZE    15504

int     arr[MAX_SIZE+1];
short   order[16][16][16][16][16][16];

int     get_sum_of_digit(int n)
{
    int ret = 0;

    for(;n>0;n>>=4)
    {
        ret += (n&0xf);
    }

    return  ret;
}

void    init(void)
{
    int     arr_ptr = 0;
    short   num = 0;

    for(int i=0x00000f;i<=0xf00000;i++)
    {
        if( get_sum_of_digit(i) != 15 )
        {
            continue;
        }

        arr[arr_ptr++] = i;
        order[(i&0xf00000)>>20][(i&0xf0000)>>16][(i&0xf000)>>12][(i&0xf00)>>8][(i&0xf0)>>4][i&0xf] = num++;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for(int n=1;;n++)
    {
        char    c;
        int     n1,n2,n3,n4,n5,n6;

        cin>>c;

        if( c == 'e' )
        {
            break;
        }

        if( c == 'm' )
        {
            cin>>n1>>n2>>n3>>n4>>n5>>n6;
            cout<<"Case "<<n<<": "<<order[n1][n2][n3][n4][n5][n6]<<'\n';
        }
        else
        {
            cin>>n1;
            cout<<"Case "<<n<<": "<<((arr[n1]&0xf00000)>>20)<<' '<<((arr[n1]&0xf0000)>>16)<<' '<<((arr[n1]&0xf000)>>12)<<' '<<((arr[n1]&0xf00)>>8)<<' '<<((arr[n1]&0xf0)>>4)<<' '<<(arr[n1]&0xf)<<'\n';
        }
    }

    return  0;
}