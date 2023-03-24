#include    <iostream>
#include    <vector>

using namespace std;

#define f(x)    ((x)%10)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,K;
    vector<int> num;

    cin>>N>>K;

    for(int x=1;x<=N;x++)
    {
        if( f(x)==f(K) || f(x)==f(2*K) )
        {
            continue;
        }

        num.push_back(x);
    }

    cout<<num.size()<<'\n';

    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<((i==num.size()-1)?'\n':' ');
    }

    return  0;
}