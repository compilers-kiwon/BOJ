#include    <iostream>
#include    <string>

using namespace std;

const string cons = "qwertasdfgzxcv";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  s;

    cin>>N>>s;
    cout<<((cons.find(s.back())!=string::npos)?1:0)<<'\n';

    return  0;
}