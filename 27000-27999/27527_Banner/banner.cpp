#include    <iostream>
#include    <map>

using namespace std;

#define MAX_SIZE    (200000+1)

static int  N,M,A[MAX_SIZE];
static map<int,int> cnt;

#define ceil_num(num)   (((num)*9+9)/10)
#define EXIT(str)       {cout<<(str)<<'\n';return 0;}

int input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  ceil_num(M);
}

int init(void)
{
    int max_cnt = 0;

    for(int i=1;i<=M;i++)
    {
        max_cnt = max(max_cnt,++cnt[A[i]]);
    }

    return  max_cnt;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int c = input();

    if( init() >= c )
    {
        EXIT("YES");
    }

    for(int h=1,t=M+1;t<=N;h++,t++)
    {
        int&    removed = cnt[A[h]];
        int&    added = cnt[A[t]];

        if(--removed==0) cnt.erase(A[h]);
        if(++added==c) EXIT("YES");
    }

    EXIT("NO");
}