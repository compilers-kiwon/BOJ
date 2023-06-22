#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    int64   N,cnt;

    cin>>N;
    cnt = N;

    for(int64 i=2,next;i<N;i=next+1)
    {
        next = (N-1)/((N-1)/i);
        cnt += (1+(N-1)/i)*(next-i+1);
    }

    cout<<cnt+((N==1)?0:1)<<'\n';
    return  0;
}