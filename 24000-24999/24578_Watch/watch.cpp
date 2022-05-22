#include    <iostream>

using namespace std;

#define MAX_SIZE        4
#define is_led_on(n,s)  ((((n)>>(s))&0x1)==0x1)
#define char2int(c)     ((int)(c-'0'))

char    watch[MAX_SIZE][MAX_SIZE],time[MAX_SIZE+1];

void    print_watch(void)
{
    for(int row=0;row<MAX_SIZE;row++)
    {
        cout<<watch[row][0]<<' '<<watch[row][1]<<"   "
                <<watch[row][2]<<' '<<watch[row][3]<<'\n';
    }
}

void    int2bin(int n,int pos)
{
    for(int row=MAX_SIZE-1,s=0;s<MAX_SIZE;s++,row--)
    {
         watch[row][pos] = (is_led_on(n,s)?'*':'.');
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>time;

    for(int col=0;col<MAX_SIZE;col++)
    {
        int2bin(char2int(time[col]),col);
    }

    print_watch();

    return  0;
}