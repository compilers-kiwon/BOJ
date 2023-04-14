#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define NUM_OF_BLOCKS   8
#define char2int(c)     ((int)((c)-'0'))

const set<int>  adj[NUM_OF_BLOCKS+1] = {
    {},
    {4,5},
    {},
    {4,5},
    {2,3},
    {8},
    {2,3},
    {8},
    {6,7}
};

#define is_right_order(prev,current) \
        (adj[(prev)].find((current))!=adj[(prev)].end())

int well_connected(const string& str)
{
    bool    ret = true;

    for(int i=1;i<str.length();i++)
    {
        int prev_block = char2int(str[i-1]);
        int current_block = char2int(str[i]);

        if( !is_right_order(prev_block,current_block) )
        {
            ret = false;
            break;
        }
    }

    return  ret;
}

int simulate(const string& str)
{
    return  ((str.front()=='1')&&(str.back()=='2')&&well_connected(str));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;;i++)
    {
        string  str;

        cin>>str;

        if( str == "0" )
        {
            break;
        }

        cout<<i<<". "<<(simulate(str)?"VALID":"NOT")<<'\n';
    }

    return  0;
}