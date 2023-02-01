#include    <iostream>

using namespace std;

#define IS_LUNCH(t) (12<=(t)&&(t)<=16)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T,S;

    cin>>T>>S;
    cout<<((S||!IS_LUNCH(T))?280:320)<<'\n';
    
    return  0;
}