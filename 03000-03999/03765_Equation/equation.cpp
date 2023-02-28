#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  str;

        getline(cin,str);
        if(str.empty()) break;

        cout<<str<<'\n';
    }

    return  0;
}