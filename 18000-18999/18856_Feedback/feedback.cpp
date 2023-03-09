#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (50+1)

#define TRUE    1
#define FALSE   0

int is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if( n%i == 0 )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int get_prime_number(int lower)
{
    int ret;

    for(int i=lower+1;;i++)
    {
        if( is_prime(i) == TRUE )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int init_arr(int arr[])
{
    arr[1] = 1;
    arr[2] = 2;

    return  0;
}

int build_arr(int size,int arr[])
{
    init_arr(arr);

    for(int i=3;i<size;i++)
    {
        arr[i] = arr[i-1]+1;
    }

    arr[size] = get_prime_number(arr[size-1]);

    return  0;
}

int print(int size,int arr[])
{
    cout<<size<<'\n';

    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<' ';
    }

    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE];

    cin>>N;

    build_arr(N,A);
    print(N,A);

    return  0;
}