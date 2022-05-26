#include    <iostream>

using namespace std;

#define NUM_OF_SIDES    3

int     input(int* arr)
{
    int ret = 0;

    for(int i=1;i<=NUM_OF_SIDES;i++)
    {
        cin>>arr[i];
        ret += arr[i]*arr[i];
    }

    return  ret;
}

bool    is_triangle(int sum,int* arr)
{
    bool    ret = false;

    for(int i=1;i<=NUM_OF_SIDES;i++)
    {
        if( (arr[i]*arr[i])*2 == sum )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int arr[NUM_OF_SIDES+1],sum;

        sum = input(arr);
        cout<<"Case #"<<i<<": "<<(is_triangle(sum,arr)?"YES":"NO")<<'\n';
    }

    return  0;
}