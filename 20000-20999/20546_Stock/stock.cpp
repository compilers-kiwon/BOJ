#include    <iostream>

using namespace std;

#define MAX_SIZE    14

int get_bnp(int money,int* price)
{
    int n = 0;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        n += money/price[i];
        money %= price[i];
    }

    return  (money+n*price[MAX_SIZE]);
}

int get_timing(int money,int* price)
{
    int n = 0;

    for(int i=4;i<=MAX_SIZE;i++)
    {
        int&    p1 = price[i-3];
        int&    p2 = price[i-2];
        int&    p3 = price[i-1];
        int&    p4 = price[i-0];

        if( p1<p2 && p2<p3 && p3<p4 )
        {
            money += n*p4;
            n = 0;
        }

        if( p1>p2 && p2>p3 && p3>p4 )
        {
            n += money/p4;
            money %= p4;
        }
    }

    return  (money+n*price[MAX_SIZE]);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M,P[MAX_SIZE+1];

    cin>>M;
    for(int i=1;i<=MAX_SIZE;i++) cin>>P[i];

    int junhyun = get_bnp(M,P);
    int sungmin = get_timing(M,P);
    
    cout<<((junhyun==sungmin)?"SAMESAME":
            (junhyun>sungmin)?"BNP":"TIMING")<<'\n';
    
    return  0;
}