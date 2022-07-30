#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str,prev;

    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        if( prev.find(str[i]) != string::npos )
        {
            cout<<"0\n";
            return  0;
        }

        prev.push_back(str[i]);
    }

    cout<<"1\n";
    return  0;
}