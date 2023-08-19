#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define ENCODE_LEN  4

int decode(const string& encoded,
            string& result,map<string,char>& table)
{
    for (int i=0;i<encoded.length();i+=ENCODE_LEN) {
        string  s = encoded.substr(i,ENCODE_LEN);
        map<string,char>::iterator  it = table.find(s);

        if (it == table.end()) result.push_back('?');
        else result.push_back(it->second);
    }

    return  0;
}

int input(string& encoded,map<string,char>& table)
{
    int N;
    
    cin>>N;

    for (int i=1;i<=N;i++) {
        char    c;
        string  s;

        cin>>c>>s;
        table[s] = c;
    }

    cin>>encoded;
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string enc,dec;
    map<string,char> table;

    input(enc,table);
    decode(enc,dec,table);
    cout<<dec<<'\n';

    return  0;
}