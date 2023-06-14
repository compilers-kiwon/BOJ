#include    <iostream>
#include    <string>

using namespace std;

#define half_str(s) ((s).substr(0,(s).length()/2))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  S;

    cin>>N>>S;
    cout<<(half_str(S)+half_str(S)==S?"Yes":"No")<<'\n';

    return  0;
}