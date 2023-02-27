#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int count(int score[],int min_score,int size)
{
    int ret = 0;

    for(int i=1;i<=size;i++)
    {
        ret += (score[i]>=min_score)?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE],X,Y;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    cin>>X>>Y;

    cout<<N*X/100<<' '<<count(A,Y,N)<<'\n';

    return  0;
}