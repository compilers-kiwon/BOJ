#include    <iostream>
#include    <string>

using namespace std;

#define is_included(word,text)  ((text).find((word))!=string::npos)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     cnt;
    string  w,t;

    cnt = 0;
    cin>>w;

    for(;cin>>t;)
    {
        cnt += is_included(w,t)?1:0;
    }

    cout<<cnt<<'\n';
    return  0;
}