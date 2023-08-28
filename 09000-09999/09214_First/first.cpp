#include    <iostream>
#include    <string>

using namespace std;

#define chr2int(c)  ((int)((c)-'0'))

string  get_prev(string& cur)
{
    if (cur.length()%2 != 0) return cur;

    string  ret;

    for (int i=0;i<cur.length();i+=2) {
        char    n = cur[i];
        char    c = cur[i+1];

        for (int j=0;j<chr2int(n);j++) ret.push_back(c);
    }

    return  ret;
}

string  find_first(string& cur)
{
    string  prev = get_prev(cur);
    return  (prev==cur)?prev:find_first(prev);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i=1;;i++) {
        string  s;

        cin>>s;
        if (s == "0") break;

        cout<<"Test "<<i<<": "<<find_first(s)<<'\n';
    }

    return  0;
}