#include    <iostream>
#include    <string>

using namespace std;

const static string original = "aeiouyAEIOUY";
const static string replacement = "yaeiouYAEIOU";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    string  buf;

    getline(cin,buf);
    n = stoi(buf);

    for(int i=1;i<=n;i++)
    {
        getline(cin,buf);

        for(int j=0;j<buf.length();j++)
        {
            size_t  pos = replacement.find(buf[j]);
            cout<<(pos==string::npos?buf[j]:original[pos]);
        }

        cout<<'\n';
    }

    return  0;
}