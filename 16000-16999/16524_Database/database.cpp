#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define SEPARATOR   '@'
#define BREAKER     '+'
#define SKIP        '.'

string  get_localpart_name(const string& addr)
{
    string  ret;

    for (int i=0;i<addr.find(SEPARATOR);i++) {
        if (addr[i] == BREAKER) break;
        if (addr[i] == SKIP) continue;
        ret.push_back(addr[i]);
    }

    return  ret;
}

string  get_provider_name(const string& addr)
{
    return  addr.substr(addr.find(SEPARATOR)+1);
}

pair<string,string> get_user(const string& addr)
{
    return  {get_localpart_name(addr)
                    ,get_provider_name(addr)};
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    set<pair<string,string>> users;

    cin>>N;

    for (int i=1;i<=N;i++) {
        string  addr;

        cin>>addr;
        users.insert(get_user(addr));
    }

    cout<<users.size()<<'\n';
    return  0;
}