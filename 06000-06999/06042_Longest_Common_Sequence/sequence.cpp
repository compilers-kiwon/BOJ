#include    <iostream>

using namespace std;

#define MAX_SIZE    (180+1)

int L1,L2,S1[MAX_SIZE],S2[MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

void    input(void)
{
    cin>>L1>>L2;

    for(int i=1;i<=L1;i++)
    {
        cin>>S1[i];
    }

    for(int i=1;i<=L2;i++)
    {
        cin>>S2[i];
    }
}

bool    compare_subarr(int* small_arr,int from,int size,int big_len,int* big_arr)
{
    for(int i=1;(i+size-1)<=big_len;i++)
    {
        bool    result = true;

        for(int j=0;j<size;j++)
        {
            if( small_arr[from+j] != big_arr[i+j] )
            {
                result = false;
                break;
            }
        }

        if( result == true )
        {
            return  true;
        }
    }

    return  false;
}

int     find_subarr(int small_len,int* small_arr,int big_len,int* big_arr)
{
    for(int len=small_len;len>=1;len--)
    {
        for(int i=1;(i+len-1)<=small_len;i++)
        {
            if( compare_subarr(small_arr,i,len,big_len,big_arr) == true )
            {
                return  len;
            }
        }
    }

    return  0;
}
int     get_length_of_the_longest_contiguous_subsequence(void)
{
    int ret;

    if( L1 < L2 )
    {
        ret = find_subarr(L1,S1,L2,S2);
    }
    else
    {
        ret = find_subarr(L2,S2,L1,S1);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_length_of_the_longest_contiguous_subsequence()<<'\n';

    return  0;
}