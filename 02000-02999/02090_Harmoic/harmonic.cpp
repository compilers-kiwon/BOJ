#include    <iostream>

using namespace std;

typedef long long int   int64;

#define MAX_SIZE    (9+1)

static int      N;
static int64    A[MAX_SIZE];

int     input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  0;
}

int64   multiply(int64 nums[],int size)
{
    int64   ret = 1;

    for(int i=1;i<=size;i++)
    {
        ret *= nums[i];
    }

    return  ret;
}

int64   get_gcd(int64 a,int64 b)
{
    int64   big = max(a,b);
    int64   small = min(a,b);
    
    for(int64 mod=big%small;mod!=0;mod=big%small)
    {
        big = small;
        small = mod;
    }

    return  small;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int64   a,b,g;

    b = multiply(A,N);
    a = 0;

    for(int i=1;i<=N;i++)
    {
        a += b/A[i];
    }

    g = get_gcd(a,b);
    cout<<b/g<<'/'<<a/g<<'\n';

    return  0;
}