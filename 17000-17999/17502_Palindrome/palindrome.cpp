#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  p;

    cin>>N>>p;

    for(int head=0,tail=N-1;head<=tail;head++,tail--)
    {
        if( p[head]=='?' && p[tail]=='?' )
        {
            p[head] = p[tail] = 'a';
        }
        else
        {
            p[head] = (p[head]=='?')?p[tail]:p[head];
            p[tail] = (p[tail]=='?')?p[head]:p[tail];
        }
    }

    cout<<p<<'\n';

    return  0;
}