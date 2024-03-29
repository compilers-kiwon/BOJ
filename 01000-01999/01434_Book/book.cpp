#include    <iostream>

using namespace std;

#define MAX_SIZE    (50+1)

#define get_wasted_space(total,used)    ((total)-(used))

int N,M,A[MAX_SIZE],B[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<=M;i++)
    {
        cin>>B[i];
    }
}

int     simulate(void)
{
    int ret,current,book,box;

    for(ret=current=0,book=box=1;book<=M;)
    {
        if( current+B[book] <= A[box] )
        {
            current += B[book];
            book++;
        }
        else
        {
            ret += get_wasted_space(A[box],current);
            box++;current=0;
        }
    }

    ret += get_wasted_space(A[box],current);

    for(box++;box<=N;box++)
    {
        ret += A[box];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    cout<<simulate()<<'\n';

    return  0;
}