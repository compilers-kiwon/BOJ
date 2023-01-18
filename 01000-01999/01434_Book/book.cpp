#include    <iostream>

using namespace std;

#define MAX_SIZE    (50+1)

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
            ret += A[box]-current;
            box++;current=0;
        }
    }

    ret += A[box]-current;

    for(box++;box<=N;box++)
    {
        ret += A[box];
    }
    
    return  ret;
}

int     main(void)
{
    input();
    cout<<simulate()<<'\n';

    return  0;
}