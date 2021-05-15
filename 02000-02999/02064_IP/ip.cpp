#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

int n,ip[MAX_SIZE],addr,mask;

void    input(void)
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;

        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        ip[i] = (a<<24)|(b<<16)|(c<<8)|(d<<0);
    }
}

int     main(void)
{
    input();

    for(int i=31;i>=0;i--)
    {
        int     bit = (ip[1]&(1<<i));
        bool    is_same = true;

        for(int j=2;j<=n;j++)
        {
            if( (ip[j]&(1<<i)) != bit )
            {
                is_same = false;
                break;
            }
        }

        if( is_same == true )
        {
            addr |= bit;
            mask |= (1<<i);
        }
        else
        {
            break;
        }
    }

    printf("%d.%d.%d.%d\n",(addr>>24)&0XFF,(addr>>16)&0XFF,(addr>>8)&0XFF,(addr>>0)&0XFF);
    printf("%d.%d.%d.%d\n",(mask>>24)&0XFF,(mask>>16)&0XFF,(mask>>8)&0XFF,(mask>>0)&0XFF);

    return  0;
}