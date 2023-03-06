#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)

#define TRUE    1
#define FALSE   0

static int  N,A[MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define is_increased(pos,offset,flag) \
    {int tmp=(pos)+(offset);if(IN_RANGE(1,tmp,N)\
            &&A[(pos)]<A[tmp])(pos)=tmp,(flag)=true;}

int is_mountain(void)
{
    int ret = TRUE;

    for(int h=1,t=N;h!=t;)
    {
        bool    updated = false;

        is_increased(h,1,updated);
        is_increased(t,-1,updated);
        
        if( updated == false )
        {
            ret = FALSE;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    cout<<(is_mountain()?"YES":"NO")<<'\n';

    return  0;
}