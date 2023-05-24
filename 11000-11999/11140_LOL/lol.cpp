#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_NUM_OF_OPERATIONS   3

const static vector<string> str[MAX_NUM_OF_OPERATIONS] = {
    {"lol"},
    {"lo","ll","ol",
     "lal","lbl","lcl","ldl","lel","lfl","lgl","lhl","lil",
     "ljl","lkl","lll","lml","lnl","lpl","lql","lrl","lsl",
     "ltl","lul","lvl","lwl","lxl","lyl","lzl"},
    {"l","o","l"}
};

#define is_included(str,sub)    ((str).find((sub))!=string::npos)

int build_lol(const string& current)
{
    int ret;

    for(ret=0;ret<MAX_NUM_OF_OPERATIONS;ret++)
    {
        bool  found = false;
        const vector<string>&   s = str[ret];

        for(int i=0;i<s.size();i++)
        {
            if( is_included(current,s[i]) )
            {
                found = true;
                break;
            }
        }

        if( found == true )
        {
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  s;

        cin>>s;
        cout<<build_lol(s)<<'\n';
    }

    return  0;
}