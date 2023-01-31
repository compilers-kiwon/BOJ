#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define TARGET_NUM  5

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    map<string,int> state;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int X;
        string  S;

        cin>>S>>X;
        state[S] += X;
    }

    bool    found = false;

    for(map<string,int>::iterator it=state.begin();it!=state.end();it++)
    {
        if( it->second == TARGET_NUM )
        {
            found = true;
            break;
        }
    }

    cout<<(found?"YES\n":"NO\n");

    return  0;
}