#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)

static int  N,K,M,A[MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int reverse_number(int len)
{
    int start_pos = (len>0)?1:N+len+1;
    int end_pos = (len>0)?len:N;

    if( !IN_RANGE(start_pos,K,end_pos) )
    {
        return  K;
    }

    return  (start_pos+end_pos-K);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>K>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    for(int n=1;n<=M;n++)
    {
        int i;

        cin>>i;
        K = reverse_number(i);
    }

    cout<<K<<'\n';
    return  0;
}