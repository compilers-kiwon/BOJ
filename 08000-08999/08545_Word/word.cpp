#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;

    cin>>str;

    for(int i=str.length()-1;i>=0;i--)
    {
        cout<<str[i];
    }

    cout<<'\n';

    return  0;
}