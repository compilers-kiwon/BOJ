#include    <iostream>
#include    <string>

using namespace std;

static int cnt[0x100];
const string symbol = "HIARC";

int count_required_symbols(const string& in)
{
    for(int i=0;i<in.length();i++)
    {
        char    c = in[i];

        if( symbol.find(c) != string::npos )
        {
            cnt[c]++;
        }
    }

    return  0;
}

int get_num_of_available_emoji(void)
{
    int ret = 0x7FFFFFFF;

    for(int i=0;i<symbol.length();i++)
    {
        ret = min(ret,cnt[symbol[i]]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  str;

    cin>>N>>str;

    count_required_symbols(str);
    cout<<get_num_of_available_emoji()<<'\n';

    return  0;
}