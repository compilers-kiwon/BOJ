#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define get_char_at_pos(str,pos) \
    ((pos)<(str).length()?(str)[(pos)]:' ')

int input(vector<string>& w)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string  s;

        cin>>s;
        w.push_back(s);
    }

    return  0;
}

string  decode(const vector<string>& w)
{
    string  ret;

    ret.push_back(w.front().front());

    for(int i=1;i<w.size();i++)
    {
        int prev_len = w[i-1].length()-1;
        ret.push_back(get_char_at_pos(w[i],prev_len));
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  words;

    input(words);
    cout<<decode(words)<<'\n';

    return  0;
}