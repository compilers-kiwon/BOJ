#include    <iostream>
#include    <string>

using namespace std;

const static string str = "WelcomeToSMUPC";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string s = " ";

    cin>>N;
    for (;s.length()<=N;s+=str);
    cout<<s[N]<<'\n';

    return  0;
}