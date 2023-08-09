#include    <iostream>
#include    <string>

using namespace std;

#define RED     'R'

int count(const string& str,char c)
{
    int ret = 0;
    for(int i=0;i<str.length();i++) ret+=(str[i]==c)?1:0;
    return  ret; 
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,K;
    string  S;

    cin>>N>>K>>S;
    cout<<(count(S,RED)==K?'W':'R')<<'\n';

    return  0;
}