#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int find_number(int* arr,int size,int pos,int n)
{
    int ret = 0;

    for(int i=pos;i<=size;i++)
    {
        if( arr[i] == n )
        {
            ret++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE],cnt;

    cin>>N;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            cnt += find_number(A,N,j+1,A[i]*A[j]);
        }
    }

    cout<<cnt<<'\n';

    return  0;
}