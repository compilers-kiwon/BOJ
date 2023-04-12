#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static map<char,string> compressor;

int read_compressor(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        char    c;
        string  str;

        cin>>str>>c;
        compressor[c] = str;
    }

    return  0;
}

int simulate(void)
{
    int     S,E;
    string  compressed,restored;
    
    cin>>compressed>>S>>E;
    restored = " ";

    for(int i=0;i<compressed.length();i++)
    {
        restored += compressor[compressed[i]];
    }

    for(int i=S;i<=E;i++)
    {
        cout<<restored[i];
    }

    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_compressor();
    simulate();

    return  0;
}